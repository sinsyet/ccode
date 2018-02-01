#include <stdio.h>

// 演示二重指针可以当指针数组使用
// void main(int argc, char *argv[])

void fun(char **argv,int argc)
{
	int i = 0;
	for(; i < argc; i++)
	{
		printf("--1 %s\n",*(argv+i));
		printf("--2 %s\n",argv[i]);
	}
	/*
	--1 hello
	--2 hello
	--1 everybody
	--2 everybody
	--1 are
	--2 are
	--1 you
	--2 you
	--1 ok
	--2 ok
	*/
}

void main()
{
	char *str[] = {"hello","everybody","are","you","ok"};
	fun(str,5);
}

// void main(int argc, char *argv[])
void main1(int argc, char **argv)
{
	printf("argc is:%d\n",argc);
	int i = 0;
	for(; i < argc; i ++)
	{
		printf("%s\n",argv[i]);
	}
}
