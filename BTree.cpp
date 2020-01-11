#include <iostream>
using namespace std;

typedef struct Bnode{
	char data;
	struct Bnode*lchild, *rchild;
}Bnode, *Btree;

void createTree(Btree &T)
{
	//Please input in preorder
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = new Bnode;
		T->data = ch;
		createTree(T->lchild);
		createTree(T->rchild);
	}
}

void preorder(Btree T)
{
	if(T)
	{
		cout << T->data << " ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

void inorder(Btree T)
{
	if(T)
	{
		inorder(T->lchild);
		cout << T->data << " ";
		inorder(T->rchild);
	}
}

void postorder(Btree T)
{
	if(T)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		cout << T->data << " ";
	}
}

int main()
{
	Btree mytree;
	cout << "Please input the node by preorder" << endl;
	createTree(mytree);
	cout << endl;
	cout << "preorder is:" << endl;
	preorder(mytree);
	cout << endl;
	cout << "inorder is:" << endl;
	inorder(mytree);
	cout << endl;
	cout << "postorder is:" << endl;
	postorder(mytree);
	cout << endl;
}
