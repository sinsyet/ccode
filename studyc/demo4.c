#include <stdio.h>	// ����ͷ�ļ�, �ڱ����ʱ��, �ͻ���ļ��еĺ������뵽���λ�� 
#include <math.h> 

// �궨��, ��Ԥ�����ʱ��������ͻ�Ѵ����е�����PI��3.14159���
// ����ָ������, Ҳ�����ٸ�ֵ 
#define PI 3.14

// 1. ���������Բ�뾶����ܳ������ 
void main()
{
	double radius;	// Բ��
	printf("������Բ�뾶:");
	scanf("%lf",&radius);	// ¼���ʱ��, �ǽ�radius��ָ��ֵ����¼���� 
	
	// r��3�η�, -> math.h pow(r,3)
	printf("�ܳ�: %lf\n",2 * PI * radius);
	printf("���: %lf\n",PI * pow(radius, 2)); 
	
	// ����
	int a,b,c,d;
	a = 10;
	b = 010;
	c = 0x10; 
	d = 0b10;
	printf("%d,%d,%d,%d\n",a,b,c,d);
	printf("%d,%o,%x,%d",a,b,c,d);	// û����������Ƶ� 
}
