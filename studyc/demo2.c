#include <stdio.h>

void main()
{
	printf("%d\n",sizeof(float));		// 4字节, 32个比特, 24个底数位, 8个指数位 
	printf("%d\n",sizeof(double));		// 8字节,  
	printf("%d\n",sizeof(int));			// 4字节,
	float min = 4e-1;	// 相当于是4 * 10(-1)次方 , 就是4/10 = 0.4 
	printf("%f\n",min);	// 0.4 
	/*  
		float的取值范围:
			24个底数位                   8个指数位
			1个符号 + 23个小数位         1个符号 + 7个指数位
			标准指数形式:
			0.1234e54321	// 小数部分, 第一位小数不能是0, 小数点左侧必须是0,
			                // 指数只能是整数 
		// ok, 搞不懂这个东西 
	*/ 
	printf("long double=%d\n",sizeof(long double));	// 长双精度浮点类型	// 64位, double是8位, long相当于是 * 2
	float f = 1234.1415926;		// 1234.141602,输出结果, 单精度float的有效位数是7位, 
								// 包括整数和小数部分(1234.141,7位), 592 -> 602, 是四舍五入的 
	printf("f=%f",f); 
	
} 
