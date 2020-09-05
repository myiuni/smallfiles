/*************************************************************************
    > File Name: queue.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年09月05日 星期六 15时53分51秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define maxlen 10
typedef struct {
	int data[maxlen];
	int front;
	int rear;
}queue;

queue *setqueue()
{
	queue *q;
	q = (queue *)malloc(sizeof(queue));
	q->front = 0;
	q->rear = 0;
	return q;
}

int queuefull(queue *q)
{
	if (q->front == (q->rear + 1) % maxlen)
		return 1;
	else
		return 0;
}

int queueempty(queue *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void add(queue *q, int x)
{
	if (!queuefull(q)) {
		q->rear = (q->rear+1)%maxlen;
		q->data[q->rear] = x;
	} else {
		printf("queue full\n");
	}
}

void delete(queue *q)
{
	if (!queueempty(q))
		q->front = (q->front+1) % maxlen;
	else
		printf("queue empty\n");
}

int main()
{
	queue *q;
	q = setqueue();
	add(q,1);
	add(q,2);
	add(q,3);
	add(q,4);
	add(q,5);
	delete(q);
	printf("pop is : %d\n", q->data[q->front]);
	delete(q);
	printf("pop is : %d\n", q->data[q->front]);
	delete(q);
	printf("pop is : %d\n", q->data[q->front]);
	delete(q);
	printf("pop is : %d\n", q->data[q->front]);
	delete(q);
	printf("pop is : %d\n", q->data[q->front]);
}

