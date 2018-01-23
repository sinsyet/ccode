#include <stdio.h>

// 约舍夫环;
// 录入n, m; n表示数组包含1,2,3,...n个元素; m表示数到m后指向的元素出局
// 显示最后出局的数, 以及每次出局的出局顺序 

void init_arr(int *arr, int len)
{
	int i; 
	for(i = 0; i < len; i ++)
	{
		arr[i] = i + 1; 
	} 
}

void printf_iarr(int *arr, int len)
{
	int  i;
	for(i = 0; i < len; i++)
	{
		printf("%2d ",arr[i]);
	} 
	printf("\n");
}

void main()
{
	int n, m;
	printf("input n,m, splite by \',\':");
	scanf("%d,%d",&n,&m);
	printf("n=%d, m=%d\n",n,m); 
	
	// 初始化数组 
	int iarr[n]; 
	init_arr(iarr,n); 
	// printf_iarr(iarr,n);
	
	int report_num = 0;	// 报数的变量 
	while(1)
	{
		
	} 
}
