#include <stdio.h>

void trans_uid(unsigned char *id_card,unsigned long *result);
void main()
{
	// 不能写成char[] id_card 
	unsigned char id_card[] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};
	unsigned long result;
	trans_uid(id_card,&result);
	printf("long-size: %d",sizeof(long)); 	// 4
}
/*
	c语言中的long类型也是4个字节的 
	int 和long类型的区别
	早期的操作系统是16位, 规定
		int , 2个字节
		long, 4个字节
	
	后来发展到32位系统, 规定
		int, 4个字节
		long, 4个字节
	
	再后来, 64位系统, 规定
		int, 4个字节
		long, 8个字节  
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
