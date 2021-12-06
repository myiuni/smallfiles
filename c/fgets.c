/*************************************************************************
    > File Name: fgets.c
    > Author: myiuni
    > Mail: myiuni@163.com 
    > Created Time: 2021年12月06日 星期一 18时59分04秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    char buf[128];
    while (fgets(buf, 128, fp) != NULL) {
        printf("buf = %s\n", buf);
        sleep(1);
    }
}
