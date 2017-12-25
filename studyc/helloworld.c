#include <stdio.h>
#include <string.h>

// �������� 
void encrypt_phone_number(char *phone,unsigned char *arr);
void printf_uchar_arr(unsigned char *arr); 
void decode_phone_number(unsigned char *arr, char *phone); 

int main()
{
	unsigned char arr[11]; 	// ����Ҫ��ʼ�� 
	encrypt_phone_number("12345678911", arr);	// c���Բ��Ƽ���java����ֱ��return����, �ᱨ���� 
	                                            // ���Ǵ��������ָ��, �ɺ���ȥ����ָ��(��ֵ��ɾ��) 
	printf_uchar_arr(arr); 
	char phone[11];
	decode_phone_number(arr,phone); 
	system("pause"); 
	return 0;
}

void printf_uchar_arr(unsigned char *arr)
{

	int i = 0;	// ��֧����for������i 
	for(;i < 1000;i ++)
	{
		if(arr[i] == 0)
		{
			// ò��Ҳ����ͨ��sizeof�ķ�ʽ�������ĳ���, ֻ��ͨ���ж�
			// arr[i] == 0��ʱ����Ϊ�����Ѿ�������, 
			// c��c++����������Խ��, ���������ʱ��iһֱ����, ��ô�ڴ�ͻ�������Ӧ���ڴ�ֵ 
			printf("len=%d\n",i); 
			break; 
		} 
		printf("arr[%d]=%02x\n",i,arr[i]); 
	} 
} 

// �򵥼����ֻ����� 
void encrypt_phone_number(char *phone,unsigned char *arr)
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
// ���� 
void decode_phone_number(unsigned char *arr, char *phone)
{
	int i = 0;
	for(;i < 1000; i++)
	{
		if(arr[i] == 0)
		{
			break;
		}
		phone[i] = ~(char)arr[i]; 
		// printf("progress: %d",i); 
	}
	printf("%s\n",phone); 
}
