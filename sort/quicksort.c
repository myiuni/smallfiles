/*************************************************************************
    > File Name: quicksort.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年08月30日 星期日 09时37分14秒
 ************************************************************************/

#include <stdio.h>

int partition(int a[], int left, int right)
{
	int low, high, x;
	low = left;
	high = right;
	x = a[left];
	while(low < high) {
		while(a[high] >= x && low < high) 
			high--;
		//when the last time low=high, if don't use (low < high), high will lower than low
		if (low < high) {
			a[low] = a[high];
			low++;
		}
		while(a[low] < x && low < high)
			low++;
		if (low < high) {
			a[high] = a[low];
			high--;
		}
	}
	a[low] = x;
	return low;
}

void quicksort(int a[], int low, int high)
{
	int mid;
	if (low < high) {
		mid = partition(a, low, high);
		quicksort(a, low, mid-1);
		quicksort(a, mid+1, high);
	}
}

int main()
{
	int a[] = {3,5,1,6,7,8,4,9,2};
	int len = sizeof(a) / sizeof(int);
	printf("Befort sort is : \n");
	for (int i = 0; i < len; i++)
		printf("%d\t", a[i]);
	printf("\n");
	quicksort(a, 0, len);
	printf("After sort is : \n");
	for (int i = 0; i < len; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
