#include <stdio.h>

char *m_strcpy(char *dst, const char *src)
{
	while (*src != '\0') {
		dst++ = src++;
		printf("*dst is %c\n", dst);
		printf("dst address is %p\n", dst);
	}
	return dst;

}

int main()
{
	char a[6];
	char b[] = "abasf";
	m_strcpy(a, b);
	printf("a = %s", a);
}
