/*************************************************************************
    > File Name: strtest.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年11月15日 星期日 09时55分10秒
 ************************************************************************/

#include <stdio.h>

int main()
{
	char c[] = {'a', 'b', '\0','c', '\0'};
	printf("c = %s\n", c);
	printf("size of c are: %ld\n", sizeof(c));
	return 0;
}
