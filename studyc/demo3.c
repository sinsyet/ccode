#include <stdio.h>

// char学习 
void main()
{
	int i,j=1;
    while(j)
    {
    	for(i=0;i<=5;i++)
        {
           printf("%d,",i);
        }
        j=0;
    }
    // windows系统下 /b命令不行, 想到ubuntu系统测试 
    printf("\b");
    // c语言中的char 只占一个字节, 不能 
} 
 
