#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �������26���ź������ĸ

void swap(char *c1, char *c2)
{
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp; 
} 

void printf_arr2(char *arr, int len)
{
	int i= 0;
	char c; 
	for(; i < len; i++)
	{
		c = *(arr+i);
		if(c == 0) continue; 
		printf("%c ",c);
	} 
	printf("\n");
}
void init_arr(char *arr, int len)
{
	srand(time(NULL));
	int i, j;
	char c; 
	for(i = 0; i < len; i++)
	{
		c = (rand() % 2 ? 'a' : 'A') + rand() % 26;
		if(i == 0)
		{
			*arr = c; 
		}
		else
		{
			if(c < arr[i - 1])
			{
				j = i - 1;
				// printf_arr2(arr,len); 
				while(j >= 0 && *(arr + j) > c)
				{
					*(arr + j + 1) = *(arr + j);
					j --; 
					
				} 
				*(arr + j + 1) = c;    // �������ľ���: while�����, Ϊʲô��j >= 0������ j > 0; ����u A, �������, j > 0�Ͳ��ܰ�����Ϊ0��Ԫ��������; 
				// printf_arr2(arr,len);  // Ϊʲô������(arr + j + 1) ������arr + j;  ��Ϊ�����whileѭ���������һ����Ȼ��j--, ��������Ԫ�����Ƶ�����, ���Ծ��ǵ�ǰҲ���� j - 1 + 1��Ԫ�� = c; 
			}
			else
			{
				*(arr + i) = c;
			} 
		} 
	} 
} 

void printf_arr(char *arr, int len)
{
	int i = 0;
	for(; i < len; i++)
	{
		printf("%c ",*(arr+i));
	}
	printf("\n"); 
}

void main()
{
	int len = 26; 
	char *arr = calloc(len,sizeof(char)); 
	init_arr(arr, len);
	printf_arr(arr,len); 
} 
