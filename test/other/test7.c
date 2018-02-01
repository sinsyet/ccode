#include <stdio.h>

void str1(char *s)
{
	printf("s++: %s\n",++s);// ello world
	printf("(*s)++: %d\n",*s);// *s表示的是字符串第一个字符的值
}

void main()
{
	// 指针
	str1("hello world");
}
