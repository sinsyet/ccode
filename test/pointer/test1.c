#include <stdio.h>
#include <stdlib.h>

// 指针数组

void main()
{
	char *arr[3];
	int i = 0;
	for(; i < 3; i++)
	{
		arr[i] = malloc(sizeof(char) * 10);
	}
	scanf("%5s,%5s,%5s",arr[0],arr[1],arr[2]);
	printf("%s,%s，%s\n",arr[0],arr[1],arr[2]);
	/*
		eeeee,aaaaa,ccccc
		eeeee,aaaaa，ccccc
	*/
}

void main5()
{
	char *s1 = malloc(sizeof(char) * 10);
	scanf("%s",s1);
	printf("s1:%s\n",s1);
	/*
		fuckyou
		s1:fuckyou

	main4中s1不能接收scanf字符串的原因是s1是没有指向内存地址，所以无法存储
	*/
}


void main4()
{
	char *s1;
	char s2[10];
	scanf("%4s,%s",s2,s1);
	printf("s2:%s,s1:%s\n",s2,s1);
	/*
	scanf("%s,%s",s2,s1);
	fuck,you
	s2:fuck,you,s1:(null)

	scanf("%4s,%s",s2,s1);
	fuck,you
	s2:fuck,s1:(null)
*/
}

void main3()
{
	char *s;
	s = "shit";
	printf("%s %p",s,s);
	/*
		shit 0x400858
	*/
}


void main2()
{
	char *str1 = "hello";
	char str2[10] = "hello";
	char *str3 = "hello";
	printf("str:%p %s;\t str2:%p %s; str3：%p %s\n",str1,str1,str2,str2,str3,str3);
	/*
		str:0x400838 hello;	 str2:0x7ffe6b7f0700 hello; str3：0x400838 hello
	PS: str和str3是指向常量区; 它们保存到额地址值也一样；
	str2指向栈区，常量区的地址值小于栈区的
	*/
}


// test main1
void main1()
{
	// 这个其实是char* 的数组，而不是arr[]的指针
	char *arr[] = {"HI","Fuck","YOU"};
	int i = 0;
	printf("%p\n",&i);
	for(; i < 3; i++)
	{
		printf("%p\t%s\n",arr[i],arr[i]);
	}
	/*
		0x7ffc613ed4ec 栈内存
		0x400634	HI  常量区
		0x400637	Fuck 常量区
		0x40063c	YOU 常量区
	*/
	printf("----------------------------------------\n");
//	char *arr1[3];	// *arr是野指针，没有意义，对其赋值的时候报段错误;	
//	printf("%p %p,%p,%p\n",arr1,arr1[0],arr1[1],arr1[2]);
	// 0x7ffe3e4f6c00 0x4006c0,0x400500,0x7ffe3e4f6d00
	// 下面的scanf代码报段错误,
//	scanf("%s,%s,%s",arr1[0],arr1[1],arr1[2]);

//	char *str;
//	scanf("%s",str);
//	printf("str:%s\n",str);
	/*
		wawa 
		str:(null)
	*/
	char ss[10];
	scanf("%s",ss);
	printf("ss: %s\n",ss);
	/*
		FuckYou
		ss: FuckYou
	*/
}
