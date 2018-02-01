#include <stdio.h>

void main()
{
// 	int *arr = {1,2,3};
	int arr[] = {1,2,3};
	int *tmp = &arr[2];
	printf("%p,%d\n",&arr[2],arr[2]);
	printf("%p,%d\n",tmp,*tmp);	
}
