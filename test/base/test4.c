#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 4

void main()
{
	// 二级指针模拟二维数组
	int **arr = malloc(sizeof(int*) * LEN);
	int i = 0, j = 0;
	srand(time(NULL));
	for(; i < LEN; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * LEN);
		j = 0;
		for(; j < LEN; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}

	// printf
	i = 0;
	j = 0;
	for(; i < LEN; i++)
	{
		j = 0;
		for(; j < LEN; j++)
		{
			printf("%5d",arr[i][j]);
		}
		printf("\n");
	}
}
