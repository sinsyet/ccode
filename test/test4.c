#include <stdio.h>

void printf_str(char *s);

void main()
{
	/*
		需求: 用putchar打印出一个字符串
	*/
	printf_str("hello world");
}

void printf_str(char *s)
{
	while(*s!='\0')
	{
		putchar(*s);
		s++;
	}
	putchar('\n');
}
