/*************************************************************************
    > File Name: is_prime.c
    > Author: 冷倾殇
    > Mail: 1500428751@qq.com 
    > Created Time: 2020年05月10日 星期日 15时24分30秒
 ************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n)
{
	int divisor;

	if (divisor < 1)
		return false;
	for (divisor = 2; divisor * divisor <= n; divisor++)
		if (n % divisor == 0)
			return true;
	return false;
}

int main()
{
	int n;
	printf("Please input the number: ");
	scanf("%d", &n);
	if (is_prime(n))
		printf("This number is prime\n");
	else
		printf("No! This number is not prime");
}


