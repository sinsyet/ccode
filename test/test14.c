#include <stdio.h>

void printf_p_d(char *s,int i)
{
	printf("%s: %p,%d\n",s,&i,i);
}

void main()
{
	/*
		辨析
		const int a;
		int const a;
		const int *a;
		int *const a;
		const *int a;
	*/
	const int a = 13;	// 只能在这一行初始化
	// a = 13;
	int const b = 14;
	// b = 14;
	printf("a:%p,%d\n",&a,a);
	printf("b:%p,%d\n",&b,b);
	/*
		a:0x7ffcca220ac8,0
		b:0x7ffcca220acc,0
		a和b定义方式的意义其实都一样, 都是定义一个int常量, 它们的内存位置
		都是栈内, a和b刚好相差4个字节，其初始化值没有意义，这一次是0，说不定下一次就
		变成其他的值了;
	*/
	
	printf_p_d("a",a);
	printf_p_d("b",b);
	
	const int *c = &a;
	int *const d = &a;
	int const *e = &a;
	
}
