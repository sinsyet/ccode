#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ʹ������ָ�����Ԫ�صĴ洢�Լ��������

void init_arr(int *arr, int len)
{
	// ��������������������� 
	srand(time(NULL));
	
	// forѭ�������鸳ֵ
	int i;
	for(i = 0; i < len; i++)
	{
		*arr++ = (rand() % 100);
		// *arr++ = (rand() % 100);��ʵ�� *arr = rand() % 100; arr++;
		// arr++, ��ʾָ��λ+1, int���͵�ָ��λ+1�ǿ��4���ֽ�
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
		printf("%02d ",*(arr + i));	// *arr��ʾȡ�������ַ�洢��ֵ 
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
