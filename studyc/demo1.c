#include <stdio.h>	// standard input/output,��׼���������


/* ----------------------------- */
// ��������
void add(int i1,int i2, int* sum_pointer); 	// ����д�� *int sum, ����д��int* sum, int *sum 
/* ----------------------------- */ 

// ������ 
void main()
{
	int x, y, sum; 
	
	printf("input x:");
	scanf("%d",&x);		// ¼����Ϻ���Զ����� 
	// printf("\n");
	
	printf("input y:");
	scanf("%d",&y);		// ¼����Ϻ���Զ����� 
	// printf("\n");
	
	add(x,y,&sum);
	
	printf("sum=%d\n",sum); 
} 

/*
i1, i2, ����;
sum_pointer, int���͵ı���sum�ĵ�ַָ�� 
*/
void add(int i1,int i2, int* sum_pointer)
{
	*sum_pointer = i1 + i2; 
}
