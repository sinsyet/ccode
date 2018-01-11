#include <stdio.h>

int fuck;
void fun()
{
	static int a;
	printf("%p,%d\n",&a,a);
	printf("-----------\n");
	a = 10;
	printf("%p,%d\n",&a,a);
}

void main()
{
	/*
		// 内存在BSS区域或Data区
		0x60104c,0
		-----------
		0x60104c,10
		0x60104c,10
		-----------
		0x60104c,10
		
		// 下面的变量内存位置是栈区域
		0x7ffeb50d186c,0
		-----------
		0x7ffeb50d186c,10
		ad
		0x7ffeb50d186c,32766
		-----------
		0x7ffeb50d186c,10

	*/
	fun();
	printf("ad\n");
	fun();
	printf("fuck:%p，%d\n",&fuck,fuck);
	// fuck:0x601050，0, 和上面的刚好相差4个字节
}
