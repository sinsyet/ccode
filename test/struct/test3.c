#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 使用数组指针完成元素的存储以及反向输出

void init_arr(int *arr, int len)
{
	// 给随机数发生器设置种子 
	srand(time(NULL));
	
	// for循环给数组赋值
	int i;
	for(i = 0; i < len; i++)
	{
		*arr++ = (rand() % 100);
		// *arr++ = (rand() % 100);其实是 *arr = rand() % 100; arr++;
		// arr++, 表示指针位+1, int类型的指针位+1是跨过4个字节
		// 000000000022FDA4 000000000022FDA8 000000000022FDAC ...
		// printf("%p ",arr); 
	}
} 
 
void printf_arr(int *arr, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		printf("%02d ",arr[i]);
	}
	printf("\n"); 
}

void reverse_printf_arr(int *arr, int len)
{
	int i;
	for(i = len - 1; i >= 0; i--)
	{
		printf("%02d ",*(arr + i));	// *arr表示取出这个地址存储的值 
	} 
	printf("\n");
} 

void main()
{
	const int len = 20;
	int arr[len];
	init_arr(arr, len);
	printf_arr(arr,len);
	
	reverse_printf_arr(arr,len); 
}
