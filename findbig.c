/*************************************************************************
    > File Name: findbig.c
    > Author: 冷倾殇
    > Mail: 1500428751@qq.com 
    > Created Time: 2020年05月07日 星期四 20时18分47秒
 ************************************************************************/
#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main()
{
	int b[N], i, big, small;
	printf("Please input the number.\n");
	for (int i=0; i<N; i++)
		scanf("%d",&b[i]);

	max_min(b, N, &big, &small);

	printf("The biggest is %d\n", big);
	printf("The smallest is %d\n", small);


}

void max_min(int a[], int n, int *max, int *min)
{
	*max = *min = a[0];
	for (int i=1; i<N;i++) {
		if (a[i] > *max)
			*max = a[i];
		else if (a[i] < *min)
			*min = a[i];
	}

}
