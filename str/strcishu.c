/*************************************************************************
    > File Name: strcishu.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年11月21日 星期六 16时56分27秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>


int main()
{
	char *p = "11abcd111122abcd3322abcd3333abc322qqq";
	int i = 0;
	char *tmp = NULL;
	while (1) {
		tmp = strstr(p, "abcd");
		if (tmp == NULL)
			break;
		else {
			p = tmp+strlen("abcd");
			i++;
		}
	}
	printf("Times are %d\n", i);
	return 0;
}
