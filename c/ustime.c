/*************************************************************************
    > File Name: ustime.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2021年11月14日 星期日 15时58分13秒
 ************************************************************************/
#include <stdio.h>
#include <sys/time.h>

long long ustime()
{
	struct timeval tv;
	long long usec;

	gettimeofday(&tv, NULL);
	usec = ((long)tv.tv_sec)*1000000;
	usec += tv.tv_usec;
	return usec;
}

int main()
{
	long long a;
	a = ustime();
	printf("ustime = %lld\n", a);
}
