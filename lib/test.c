#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

void main()
{
//	int a = 3, b = 4;
//	printf("before swap: a:%p,%d; b:%p,%d\n",&a,a,&b,b);
//	swap(&a,&b);
//	printf("after swap: a:%p,%d; b:%p,%d\n",&a,a,&b,b);
	
//	printf("-----------------------------------\n");
	int len = 10;
	int *arr = malloc(len * sizeof(int));
	stuff_arr(arr,len);
	printf_arr(arr,len);
//	reverse(arr,len);
//	printf_arr(arr,len);
//	printf("-----------------------------------\n");
//	bubble_sort(arr,len);
//	printf_arr(arr,len);
//	printf("-----------------------------------\n");
//	int arr2[] = {10,9,8,7,6,5,4,3,2,1};
//	bubble_sort(arr2,10);
//	printf_arr(arr2,10);
	
//	printf("-----------------------------------\n");
//	select_sort(arr,10);
//	printf_arr(arr,10);
	insert_sort(arr,len);
	printf_arr(arr,len);
	printf("-----------------------------------\n");
	insert_sort2(arr,len);
	printf_arr(arr,len);
	printf("-----------------------------------\n");
	insert_sort3(arr,len);
	printf_arr(arr,len);
	free(arr);
}	
