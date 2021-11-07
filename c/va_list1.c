/*************************************************************************
    > File Name: va_list1.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年11月07日 星期日 17时36分39秒
 ************************************************************************/
#include <stdio.h>
#include <stdarg.h>

int aveInt(int v, ...)
{
	int ret = 0;
	int i = v;
	printf("the meaning of v is %d\n", i);

	va_list ap;
	va_start(ap, v);

	while (i > 0) {
		ret += va_arg(ap, int);
		i--;
	}

	va_end(ap);
	return ret/v;
}

int main()
{
	printf("%d\n", aveInt(3,2,10));
	printf("%d\n", aveInt(6,2,4,6,8,12));
}


