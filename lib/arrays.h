#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// test ok
void swap(int* a,int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// test ok
void stuff_arr(int *arr,int len)
{
	srand(time(NULL));
	int i = 0;
	for(; i < len; i++)
	{
		arr[i] = rand() % 100;
	}
}
// test ok
void printf_arr(int *arr,int len)
{
	int i = 0;
	for(; i < len; i++)
	{
		printf("%d ",arr[i]);
		if(i != 0 && i % 10 == 0)
			printf("\n");
	}
	if((len - 1) % 10 != 0)
		printf("\n");
}
/*
	1 2 3
	0 1 2
	swap(arr[i],arr[len-1-i];

	---------
	1 2 3 4
	
*/
// test ok
void reverse(int* arr,int len)
{
	int i = 0;
	for(; i < len / 2; i++)
	{
		swap(&arr[i],&arr[len - 1 - i]);
	}
}

/*
	冒泡排序，
	例如有len个元素
	0, 1, 2, ..., len - 2, len - 1
	0, 1, 2, ..., len - 2
	...
	0, 1, 2
	0, 1
	0
*/
// OK
void bubble_sort(int *arr, int len)
{
	int i = 0, j = 0;
	// 外层的i其实是控制是多少次排序,
	// 最后一次只有一个元素， 不用比， 所以小于 len - 1, 而不是等于
	for(;i < len - 1; i++)
	{
		j = 1;
		for(;j < len - i; j++)
		{
			if(arr[j - 1] > arr [j])
			{
				swap(&arr[j - 1], &arr[j]);
			}
		}
	}
}

/*
	选择排序
	0, 1, 2, 3, 4, 5, ..., len - 1
	   1, 2, 3, 4, 5, ..., len - 1
	      2, 3, 4, 5, ..., len - 1;
		....
			       len - 1;
	选出最小或最大的拍在第一位，第二位...
*/
void select_sort(int *arr, int len)
{
	int i = 0, j = 0;
	for(; i < len - 1; i++)
	{
		j = i + 1;
		for(; j < len; j++)
		{
			if(arr[i] < arr [j])
			{
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

// 插入排序
/*
	插入排序的原理是， 保持前面的是有序的
*/
void insert_sort(int *arr, int len)
{
	int i = 1, j = 0;
	for(; i < len; i ++)
	{
		if(arr[i] > arr[i - 1])
		{
			int tmp = arr[i];
			int tmp_index = i;
			tmp = arr[i];
			for(j = i - 1; j >= 0; j --)
			{
				if(tmp > arr[j])
				{
					swap(&arr[tmp_index],&arr[j]);
					tmp = arr[j];
					tmp_index = j;
				}
				else
				{
					break;
				}
			}
		}
	}
}

void insert_sort2(int *arr,int len)
{
	int i = 1, j = 0;
	int tmp = 0;
	for(; i < len; i++)
	{
		if(arr[i] < arr[i - 1])
		{
			tmp = arr[i];
			j = i - 1;	
			while(j >= 0)
			{
				if(arr[j] > tmp)
				{
					arr[j + 1] = arr[j];
					if(j == 0)
					{
						arr[j] = tmp;
					}
				}
				else
				{
					arr[j+1] = tmp;
					break;
				}
				j --;
			}
		}
	}
}

void insert_sort3(int *arr,int len)
{
	int i, j;
	int tmp;
	for(i = 1; i < len; i++)
	{
		if(arr[i] > arr[i - 1])
		{
			tmp = arr[i];
			// move
			j = i - 1;
			while(j >= 0 && (arr[j] < tmp))
			{
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = tmp;
		}
	}
} 
// 归并排序
// 快速排序
// 二叉树排序i

