/*************************************************************************
    > File Name: guess.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年10月23日 星期六 20时58分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
	int n;
	int seed;
	srand(time(NULL));
	seed = rand() % 100 + 1;
	printf("Please input the number:\n");

	while (1) {
		scanf("%d", &n);

		if (n < seed) {
			printf("too small\n");
		} else if (n > seed) {
			printf("too big\n");
		} else {
			printf("You are right!\n");
			break;
		}
	}
}
