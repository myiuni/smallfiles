#include <stdio.h>
#include <stdlib.h>


#define maxlen 100

typedef struct {
	int data[maxlen];
	int top;
} seqstack;


seqstack *setstack()
{
	seqstack *s;
	s = (seqstack *)malloc(sizeof(seqstack));
	s->top = -1;
	return s;
}

int stackempty(seqstack *s)
{
	if (s->top >= 0)
		return 0;
	else
		return 1;
}

int stackfull(seqstack *s)
{
	if (s->top <maxlen-1 && s->top >= 0)
		return 0;
	else 
		return 1;
}

int gettop(seqstack *s)
{
	if (s->top <= maxlen-1 && s->top >= 0)
		return s->data[s->top];
	else
		printf("error\n");
}

void push(seqstack *s, int x)
{
	if (s->top < maxlen-1 && s->top >= -1) {
		s->top++;
		s->data[s->top] = x;
	} else {
		printf("error\n");
	}
}

void pop(seqstack *s)
{
	if (s->top >= 0)
		s->top--;
	else
		printf("error\n");
}

int main()
{
	seqstack *s = malloc(sizeof(seqstack));
	push(s, 5);
	push(s, 7);
	push(s, 9);
	printf("top is : %d\n", s->data[s->top]);
	pop(s);
	printf("top is : %d\n", s->data[s->top]);
	pop(s);
	printf("top is : %d\n", s->data[s->top]);
	pop(s);
	printf("top is : %d\n", s->data[s->top]);


}

