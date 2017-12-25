#include <stdio.h>	// standard input/output,标准输入输出库


/* ----------------------------- */
// 函数声明
void add(int i1,int i2, int* sum_pointer); 	// 不能写成 *int sum, 可以写成int* sum, int *sum 
/* ----------------------------- */ 

// 主函数 
void main()
{
	int x, y, sum; 
	
	printf("input x:");
	scanf("%d",&x);		// 录入完毕后会自动换行 
	// printf("\n");
	
	printf("input y:");
	scanf("%d",&y);		// 录入完毕后会自动换行 
	// printf("\n");
	
	add(x,y,&sum);
	
	printf("sum=%d\n",sum); 
} 

/*
i1, i2, 加数;
sum_pointer, int类型的变量sum的地址指针 
*/
void add(int i1,int i2, int* sum_pointer)
{
	*sum_pointer = i1 + i2; 
}
