/*************************************************************************
    > File Name: gets.c
    > Author: myiuni
    > Mail: myiuni@163.com 
    > Created Time: 2021年12月06日 星期一 18时53分32秒
 ************************************************************************/

#include <stdio.h>

int main()
{
    char buf[16];
    gets(buf);
    printf("buf = %s\n", buf);
}

