/*************************************************************************
    > File Name: trimSpace.c
    > Author: myiuni
    > Mail: myiuni@163.com 
    > Created Time: 2021年12月02日 星期四 19时38分53秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void trimSpace(char *strIn, char *strOut)
{
    int i = 0;
    int j = strlen(strIn) - 1;
    while (strIn[i] == ' ')
        i++;
    while (strIn[j] == ' ')
        j--;
    strncpy(strOut, strIn + i, j - i + 1);
    strOut[j-i+1] = '\0';
}

int main()
{
    char *a = " *fasge*  ";
    char str[12];
    trimSpace(a, str);
    printf("After trim str = %s, length = %d\n", str, strlen(str));

}
