#include <stdio.h>

void trans_uid(unsigned char *id_card,unsigned long *result);
void main()
{
	// ����д��char[] id_card 
	unsigned char id_card[] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};
	unsigned long result;
	trans_uid(id_card,&result);
	printf("long-size: %d",sizeof(long)); 	// 4
}
/*
	c�����е�long����Ҳ��4���ֽڵ� 
	int ��long���͵�����
	���ڵĲ���ϵͳ��16λ, �涨
		int , 2���ֽ�
		long, 4���ֽ�
	
	������չ��32λϵͳ, �涨
		int, 4���ֽ�
		long, 4���ֽ�
	
	�ٺ���, 64λϵͳ, �涨
		int, 4���ֽ�
		long, 8���ֽ�  
*/

void trans_uid(unsigned char *id_card,unsigned long *result)
{
	int len = sizeof(id_card) / sizeof(id_card[0]); 
	printf("len = %d\n",len);
	int i;
	unsigned long tmp = 0; 
	for(i = 4;i < len;i ++)
	{
		tmp |= (id_card[i] << ((i - 4) * 8)); 
		printf("%d = 0x%02x %lu\n",i,id_card[i],tmp);
		
	}
	printf("tmp: %lu",tmp); 
	// *result = tmp; 
}
