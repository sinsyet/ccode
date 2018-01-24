#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 随机生成26个排好序的字母

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
				*(arr + j + 1) = c;    // 体会这里的精髓: while语句里, 为什么是j >= 0而不是 j > 0; 假如u A, 这种情况, j > 0就不能把索引为0的元素做交换; 
				// printf_arr2(arr,len);  // 为什么这里是(arr + j + 1) 而不是arr + j;  因为上面的while循环做的最后一步比然是j--, 不满足做元素右移的条件, 所以就是当前也就是 j - 1 + 1个元素 = c; 
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
