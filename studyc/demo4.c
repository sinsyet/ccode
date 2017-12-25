#include <stdio.h>	// 引入头文件, 在编译的时候, 就会把文件中的函数导入到这个位置 
#include <math.h> 

// 宏定义, 在预编译的时候编译器就会把代码中的所有PI用3.14159替代
// 它不指定类型, 也不可再赋值 
#define PI 3.14

// 1. 根据输入的圆半径求出周长和面积 
void main()
{
	double radius;	// 圆心
	printf("请输入圆半径:");
	scanf("%lf",&radius);	// 录入的时候, 是将radius的指针值传给录入器 
	
	// r的3次方, -> math.h pow(r,3)
	printf("周长: %lf\n",2 * PI * radius);
	printf("面积: %lf\n",PI * pow(radius, 2)); 
	
	// 进制
	int a,b,c,d;
	a = 10;
	b = 010;
	c = 0x10; 
	d = 0b10;
	printf("%d,%d,%d,%d\n",a,b,c,d);
	printf("%d,%o,%x,%d",a,b,c,d);	// 没有输出二进制的 
}
