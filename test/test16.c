#include <stdio.h>

int factorial(int i)
{
	printf("i：%d ",i);
	if(i == 0)
	{
		return 1;
	}
	else
	{
		// factorial(i--)，一直传的是i,会报栈溢出
		return i * factorial(i - 1);
	}
}

void main()
{
	// 递归求阶乘
	int r = factorial(5);
	printf("%d\n",r);
}
