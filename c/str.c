/*************************************************************************
    > File Name: str.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年11月15日 星期日 09时46分08秒
 ************************************************************************/

#include <stdio.h>

int main()
{
	char a[] = {'a','b','c','d'};
	printf("size of a are: %ld\n", sizeof(a));

	printf("\n");

	char b[] = "abcd";
	printf("size of b are: %ld\n", sizeof(b));
	return 0;
}
