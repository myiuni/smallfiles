/*************************************************************************
    > File Name: pthread_mutex.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年11月24日 星期三 19时25分08秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int i = 0;

void *func1()
{
	while (1) {
		pthread_mutex_lock(&mutex);
		i++;
		printf("**1** in func1 i = %d\n", i);
		if (i < 17) 
			pthread_cond_wait(&cond, &mutex);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

void *func2()
{
	while (1) {
		pthread_mutex_lock(&mutex);
		i++;
		printf("**2** in func2 i = %d\n", i);
		if (i > 17)
			pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

int main()
{
	pthread_t pid1, pid2;

	pthread_create(&pid1, NULL, func1, NULL);
	pthread_create(&pid2, NULL, func2, NULL);
	
	pthread_join(pid1, NULL);
	pthread_join(pid2, NULL);

	pthread_mutex_destroy(&mutex);
}
