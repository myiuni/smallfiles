#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int i;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *thread1()
{
	while (1) {
		pthread_mutex_lock(&mutex);
		for ( i = 0; i < 7; i++)
			printf("Thread1:%d\n", i);
		pthread_mutex_unlock(&mutex);
		pthread_cond_broadcast(&cond);
		sleep(rand()%3);
	}
}

void *thread2()
{
	while (1) {
		pthread_mutex_lock(&mutex);
		while (i < 6) {
			pthread_cond_wait(&cond, &mutex);
	}
	i++;
	printf("Thread2:=====%d\n", i);
	pthread_mutex_unlock(&mutex);
	sleep(rand()%3);
	}
	
}

int main()
{
	pthread_t pid1, pid2;

	pthread_create(&pid1, NULL, thread1, NULL);
	pthread_create(&pid2, NULL, thread2, NULL);

	pthread_join(pid1, NULL);
	pthread_join(pid2, NULL);
}
