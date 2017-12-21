#include <stdio.h>
#include <string.h>

// �������� 
void decode_phone_number(char *phone,unsigned char *arr);
void printf_uchar_arr(unsigned char *arr); 

int main()
{
	unsigned char arr[11]; 	// ����Ҫ��ʼ�� 
	decode_phone_number("13212345678", arr);	// c���Բ��Ƽ���java����ֱ��return����, �ᱨ���� 
	                                            // ���Ǵ��������ָ��, �ɺ���ȥ����ָ��(��ֵ��ɾ��) 
	printf_uchar_arr(arr); 
	return 0;
}

void printf_uchar_arr(unsigned char *arr)
{
/*	int all_len = sizeof(arr);
	int single_len = sizeof(arr[0]); 
	int len = sizeof(arr)/sizeof(arr[0]); 
	printf("%d %d %d\n",all_len,single_len,len);*/ 
	int i = 0;	// ��֧����for������i 
	for(;i < 1000;i ++)
	{
		if(arr[i] == 0)
		{
			// ò��Ҳ����ͨ��sizeof�ķ�ʽ�������ĳ���, ֻ��ͨ���ж�
			// arr[i] == 0��ʱ����Ϊ�����Ѿ�������, 
			// c��c++����������Խ��, ���������ʱ��iһֱ����, ��ô�ڴ�ͻ�������Ӧ���ڴ�ֵ 
			printf("len=%d",i); 
			break; 
		} 
		printf("arr[%d]=%02x\n",i,arr[i]); 
	} 
} 

// �����ֻ����� 
void decode_phone_number(char *phone,unsigned char *arr)
{
	int len = strlen(phone); 
	printf("%d\n",len); 
	unsigned char temp;
	int i = 0;
	for(; i < len; i++)
	{
		temp = (unsigned char)phone[i];
		arr[i] = ~temp; 
	} 
}
