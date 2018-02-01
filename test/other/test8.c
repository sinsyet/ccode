#include <stdio.h>
#include <stdlib.h>

void staff(int *arr,int len)
{
	int i = 0;
	for(; i<len;i++)
	{
		arr[i] = len - i;
	}
}

void printf_arr(int *arr,int len)
{
	int i = 0;
	for(;i<len;i++)
	{
		printf("%d ",arr[i]);
		if(i % 64 == 0)
		{
			printf("\n");
		}
	}
}

void main()
{
	// 这里记得要1024个元素 × sizeof(int) 个字节
	// 否则会报： 已放弃(核心转存储)
	int *arr = malloc(1024 * sizeof(int));
	staff(arr,1024);
	printf("staff finish\n");
	printf_arr(arr,1024);
	free(arr);
}
