/*************************************************************************
    > File Name: memcpy.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年11月20日 星期六 17时33分46秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
	char dst[12];
	char *src = "hello";
	memcpy(dst, src, 6);
	printf("dst = %s\n", dst);
}
