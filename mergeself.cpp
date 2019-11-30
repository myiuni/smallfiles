#include <iostream>
using namespace std;

void merge(int A[],int low,int mid,int high)
{
	int *B = new int[high-low+1];
	int i = low,j = mid+1,k=0;
	while(i<=mid && j<=high)
	{
		if(A[i] <= A[j])
			B[k++] = A[i++];
		else 
			B[k++] = A[j++];
	}
	while(i <= mid)
		B[k++] = A[i++];
	while(j <= high)
		B[k++] = A[j++];
	for(i=low,k=0;i <=high;i++)
		A[i] = B[k++];
	delete []B;
}

void mergesort(int A[],int low,int high)
{
	if(low < high)
	{
		int mid = (low+high)/2;
		mergesort(A,low,mid);
		mergesort(A,mid+1,high);
		merge(A,low,mid,high);
	}
}

int main()
{
	int a[] = {2,3,1,5,8,4,6,9,7};
	int len = sizeof(a)/sizeof(int);
	mergesort(a,0,len-1);
	for(int k=0;k<len;k++)
		cout << a[k] << ",";
	cout << endl;
	return 0;
}
