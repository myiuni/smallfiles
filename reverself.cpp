#include <iostream>
using namespace std;

typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode,*linklist;

linklist initlist(linklist &L)
{
	int n=5;
	L = new Lnode;
	L->data = 0;
	L->next = NULL;
	linklist s;
	cout << "Please input the number" << endl;
	while(n--)
	{
		s = new Lnode;
		cin >> s->data;	
		s->next = L->next;
		L->next = s;
	}
}

/*linklist reverseList(linklist &head)          //逆置单链表
{
	linklist p, r;       //定义两个中间节点，用于顺移逆置链表节点
	if (head->next == NULL)
		return head;
	p = head;          //获取头节点地址
	r = p->next;       //获取链表第二个节点地址
	p->next = NULL;    //头节点变为尾节点，原链表表头指向空
	while (r)
	{
		p = r;
		r = r->next;
		p ->next = head;   //使第二个节点指向原先的头节点
		head = p;          //使第二个节点变为头节点，用于循环逆置
	}
	return head;
}
*/


linklist tailins(linklist &L)
{
	int n=5;
	linklist s,r;
	L = new Lnode;
	L->next = NULL;
	r = L;
	cout << "Please input the n" << endl;
	//cin >> n;
	while(n--)
	{
		s = new Lnode;
		cin >> s->data;
	//	s->next = NULL;
		r->next = s;
		r = s;
	}
	return L;
}

void printlist(linklist &L)
{
	//linklist p = L;
	linklist p;
	p = L->next;
	while(p != NULL)
	{
		cout << p->data << ",";
		p = p->next;
	}
}

reverseList(LinkedNode* pCur,LinkList& ListHead)
{
	if( (NULL==pCur)||(NULL==pCur->next) )
	{
		ListHead=pCur;
	}
	else
	{
		LinkedNode* pNext=pCur->next;
		ReverseList(pNext,ListHead); //递归逆置后继结点
		pNext->next=pCur;            //将后继结点指向当前结点。
		pCur->next=NULL;
	}
}
/*
{
	linklist first,target;
	first = L;
	target = first->next;
	first->next = NULL;
	while(target)
	{
		first->next = target->next;
		target->next = L;
		L = target;
		target = target->next;
	}
	return L;
}
*/

int main()
{
	linklist p,q;
	tailins(p);
	printlist(p);
	q = tailins(p);
	reverseList(q);
	printlist(q);
}
