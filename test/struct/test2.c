#include <stdio.h>

// Լ���;
// ¼��n, m; n��ʾ�������1,2,3,...n��Ԫ��; m��ʾ����m��ָ���Ԫ�س���
// ��ʾ�����ֵ���, �Լ�ÿ�γ��ֵĳ���˳�� 

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
	
	// ��ʼ������ 
	int iarr[n]; 
	init_arr(iarr,n); 
	// printf_iarr(iarr,n);
	
	int report_num = 0;	// �����ı��� 
	while(1)
	{
		
	} 
}
