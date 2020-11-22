/*************************************************************************
    > File Name: strcpy.c
    > Author: myiuni
    > Mail: 1792526255@qq.com 
    > Created Time: 2020年11月22日 星期日 16时17分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//这是非常标准的一种写法

char *my_strcpy(char *dst, const char *src)
{
	//首先判断src和dst是否为空
	assert((dst != NULL) && (src != NULL));
	//其实这一句没有看懂，为什么不直接返回dst?是不是多此一举
	char *tmp = dst;
	//下面这一句也是有些难以理解的
	while ((*dst++ = *src++) != '\0')
		//这一个NULL要写，不然会返回第一个字符
		NULL;
	//返回上一个赋值过的
	return tmp;
}

int main()
{
	char *a = "hello world";
	char *b = (char *)malloc(sizeof(a));
	my_strcpy(b, a);
	printf("b is %s\n", b);

	return 0;
}


