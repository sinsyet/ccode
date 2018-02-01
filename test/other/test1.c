#include <stdio.h>
#include "lib/printf_test.h"

#define C '5'

void main()
{
	printf("输入负数退出程序\n");
	int num;
	char c;
	while(1)
	{
		printf("请输入数字:");
		scanf("%d",&num);
		if(num < 0)
		{
			break;
		}
		printf("--------------------------------------------------\n");
		printf_gui(num, C, 0);
		printf("--------------------------------------------------\n");
		printf_wave(num,C);
		printf("--------------------------------------------------\n");
		printf_wave2(num,C);
		printf("--------------------------------------------------\n");
	}	
	printf("exit\n");
}
