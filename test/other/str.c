#include <stdio.h>
#include <string.h>

// strcpy, strcmp, strtok, strstr strchr
void test_strcpy();
void test_strcmp();
void test_strchr();
// void test_strtok();
void test_strstr();
void test_strtok();

// 这个函数需要声明， 可能在源文件中没有声明
char *strchrnul(const char *arr,int c);
char *strcasestr(const char *haystack,const char *needle);
void main()
{
	// test_strcpy();
	// test_strcmp();
	// test_strchr();
	// test_strstr();
	test_strtok();
}

void test_strtok()
{
	// 不能使用×str的形式传值, 因为这里的字符串
	// 是以常量的形式保存，可读不可写， 所以会报段错误
	// 段错误的意思是操作了不能操作的内存地址
	// const char *str = "hello world, are you ok?"; // 编译报错，因为参数要求的是char *str,我们定义的是const char *str,编译器知道这样肯定不行所以报错了;
	// char *str = "hello world, are you ok?";
	char str[] = "hello world,are you ok";
	// const char str[] = "hello world,are you ok"; // 同const char *str, char[]保存的是数组的第一个字符的内存地址; 
	// 在C语言中，字符串以'\0'结束
	char *delim = " ,";
	char *p = strtok(str," ");
	printf("p:%s\n",p);
	while(p = strtok(NULL,delim))
	{
		printf("P: %s\n",p);
	}
}
void test_strstr()
{
	// the strstr() 查找字符串片段出现的指针，如果没有， 返回NULL
	// man手册里只要说明了需要#define _GNU_SOURCE,表示需要声明函数
	char *haystack = "fuck you";
	char *needle = "Ck";
	char *p = strstr(haystack,needle);
	if(!p)
	{
		printf("p is NULL");	
	}
	printf("p: %s, src:%s\n",p,haystack); // 输出：ck you
	char *p2 = strcasestr(haystack,needle);
	printf("p2:%s\n",p2);
}

void test_strchr()
{
	// strchr, strrchr, strchrnul
	/*
		char *strchr(const char *s, int c);

	        char *strrchr(const char *s, int c);
	*/
	char *s = "hello";
	char *p = strchr(s,'l');
	printf("%s\n %ld",p, strlen(p));
	// llo, 3
	//  在64位系统中， size_t表示的是long unsigend int, 8位， ld格式化输出
	char *p2 = strchr(s,'y');
	if(!p2)
	{
		printf("p2 is NULL\n");
	}
	else 
	{
		printf("p2: %s",p2);
	}
	// 输出： p2 is NULL
	printf("-----------------------\n");
	char *p3 = strrchr(s,'l');
	printf("p3: %s\n",p3); // 输出了 lo, 如果没有， 则返回NULL
	printf("-----------------------\n");
	char *p4 = strchrnul(s,'l');
	printf("p4: %s\n",p4);
	char *p5 = strchrnul(s,'p');
	printf("p5: %s\n",p5);
}

void test_strcmp()
{
	/*
		int strcmp(const char *s1, const char *s2);

	        int strncmp(const char *s1, const char *s2, size_t n);

	*/
	char *str1 = "hello1";
	char *str2 = "hello2";
	int r = strcmp(str1,str2);
	printf("%d\n",r);	// -1
	printf("%d\n",strncmp(str1,str2,5));	// 0
	printf("%d\n",strcmp(str2,str1));	// 1	
	// -1
	/*
		-1, str1小于str2
		0, 相等
		1， str1大于str2
	*/
}

void test_strcpy()
{
	/*
		str: hello,p: hello, 0x7ffc80f2d290, 0x7ffc80f2d290
	*/

	char str[10];
	char *s = "hello";
	char *p = strcpy(str,s);
	printf("str: %s,p: %s, %p, %p\n",str,p,str,p);
}
