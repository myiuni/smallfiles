/*************************************************************************
    > File Name: linklist8-23.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年08月23日 星期日 09时13分52秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node *next;
}LinkList;

LinkList *setnull(LinkList *L)
{
	L->next = NULL;
	return L;
}

int LLength(LinkList *L)
{
	LinkList *p;
	int n;
	p = L->next;
	while (p) {
		p = p->next;
		n++;
	}
	return n;
}

char get(LinkList *L, int i)
{
	LinkList *p;
	int j = 1;
	p = L->next;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (i == j)
		return p->data;
	else
		return NULL;
}

char LLocate(LinkList *L, int x) 
{
	LinkList *p;
	p = L->next;
	while (p != NULL) {
		if (p->data != x)
			p = p->next;
		else
			break;
	}
	return p->data;
}

void LLinsert(LinkList *L, int i, char x)
{
	LinkList *p, *s;
	int j = 0;
	p = L;
	while (p != NULL && j < i-1) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		printf("In the error location\n");
	else {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
}

void LLdelete(LinkList *L, int i)
{
	LinkList *p, *u;
	int j = 0;
	p = L;
	while (p != NULL && j < i-1) {
		p = p->next;
		j++;
	}
	if (p != NULL && p->next != NULL) {
		u = p->next;
		p->next = u->next;
		free(u);
	}
}

LinkList *create()
{
	LinkList *L, *s, *r;
	char ch;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	r = L;
	ch = getchar();
	while (ch != '#') {
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = ch;
		s->next = NULL;
		r->next = s;
		r = s;
		ch = getchar();
	}
	return L;
}

LinkList *reverse(LinkList *L)
{
	LinkList *p, *r, *pre;
	p = L->next;
	pre = NULL;
	while (p) {
		r = p->next;
		p->next = pre;
		pre = p;
		p = r;
	}
	L->next = pre;
	return L;

}

void printlist(LinkList *L)
{
	LinkList *p;
	p = L->next;
	while (p) {
		printf("%c\n", p->data);
		p = p->next;
	}
}

int main()
{
	LinkList *L;
	create();
	LLdelete(L,4);
	printlist(L);
	return 0;
}
