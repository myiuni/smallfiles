#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct AVLNode{
	int data;
	int height;
	struct AVLNode *lchild;
	struct AVLNode *rchild;

}*AVLTree;

AVLTree Empty(AVLTree &T)
{
	if (T == NULL) return NULL;
	Empty(T->lchild);
	Empty(T->rchild);
	delete T;
	return NULL; 
}

inline int Height(AVLTree T)
{
	if (T == NULL) return 0;
	return T->height;
}

void updateHeight(AVLTree &T)
{
	T->height = max(Height(T->lchild), Height(T->rchild))+1;
}

AVLTree LL_Rotation(AVLTree &T)
{
	AVLTree temp = T->lchild;
	T->lchild = temp->rchild;
	temp->rchild = T;
	updateHeight(T);
	updateHeight(temp);
	return temp;
}

AVLTree RR_Rotation(AVLTree &T)
{
	AVLTree temp = T->rchild;
	T->rchild = temp->lchild;
	temp->lchild = T;
	updateHeight(T);
	updateHeight(temp);
	return temp;
}

AVLTree LR_Rotation(AVLTree &T)
{
	T->lchild = RR_Rotation(T->lchild);
	return LL_Rotation(T);
}

AVLTree RL_Rotation(AVLTree &T)
{
	T->rchild = LL_Rotation(T->rchild);
	return RR_Rotation(T);
}

AVLTree Insert(AVLTree &T, int x)
{
	if(T == NULL)
	{
		T = new AVLNode;
		T->lchild = T->rchild = NULL;
		T->data = x;
		T->height = 1;
		return T;
	}
	if(T->data == x) return T;
	if(x<T->data)
	{
		T->lchild = Insert(T->lchild, x);
		if(Height(T->lchild)-Height(T->rchild)==2)
		{
			if(x<T->lchild->data)
				T = LL_Rotation(T);
			else
				T = LR_Rotation(T);
		}
	}
	else
	{
		T->rchild = Insert(T->rchild,x);
		if(Height(T->rchild)-Height(T->lchild)==2)
		{
			if(x>T->rchild->data)
				T = RR_Rotation(T);
			else
				T = RL_Rotation(T);
		}
	}
	updateHeight(T);
	return T;
}

AVLTree adjust(AVLTree &T)
{
	if(T == NULL) return NULL;
	if(Height(T->lchild)-Height(T->rchild)==2)
	{
		if(Height(T->lchild->lchild)>=Height(T->lchild->rchild))
			T = LL_Rotation(T);
		else
			T = LR_Rotation(T);
	}
	if(Height(T->rchild)-Height(T->lchild)==2)
	{
		if(Height(T->rchild->rchild)>=Height(T->rchild->lchild))
			T = RR_Rotation(T);
		else
			T = RL_Rotation(T);
	}
	updateHeight(T);
	return T;
}

AVLTree Delete(AVLTree &T, int x)
{
	if(T==NULL) return NULL;
	if(T->data==x)
	{
		if(T->rchild==NULL)
		{
			AVLTree temp = T;
			T = T->lchild;
			delete temp;
		}
		else
		{
			AVLTree temp;
			temp = T->rchild;
			while(temp->lchild)
				temp=temp->lchild;
			T->data = temp->data;
			T->rchild = Delete(T->rchild,T->data);
			updateHeight(T);
		}
		return T;
	}

	if(T->data>x)
		T->lchild = Delete(T->lchild,x);
	if(T->data<x)
		T->rchild = Delete(T->rchild,x);
	updateHeight(T);
	if(T->lchild)
		T->lchild = adjust(T->lchild);
	if(T->rchild)
		T->rchild = adjust(T->rchild);
	if(T) T=adjust(T);
	return T;
}

void Preorder(AVLTree T)
{
	if(T==NULL) return ;
	cout << T->data << "\t" << T->height << endl;
	Preorder(T->lchild);
	Preorder(T->rchild);
}

void Inorder(AVLTree T)
{
	if(T==NULL) return ;
	Inorder(T->lchild);
	cout << T->data << "\t" << T->height << endl;
	Inorder(T->rchild);
}

void Posorder(AVLTree T)
{
	if(T==NULL) return ;
	Posorder(T->lchild);
	Posorder(T->rchild);
	cout << T->data << "\t" << T->height << endl;
}

void show(AVLTree T)
{
	Preorder(T);
	cout << endl;
	Inorder(T);
	cout << endl;
	Posorder(T);
}

AVLTree CreateAVL(AVLTree &T)
{
	int n,x;
	cin >> n;
	cout << "Please input the element:" << endl;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		T = Insert(T,x);
	}
	return T;
}

int main()
{
	int x;
	AVLTree root = NULL;
	root = Empty(root);
	cout << "Please Input the number n:" << endl;
	CreateAVL(root);
	cout << endl;
	show(root);
	cout << "Please Input the element wanted delete:" << endl;
	cin >> x;
	root = Delete(root,x);
	show(root);
	return 0;
}

