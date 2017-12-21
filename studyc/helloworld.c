#include <stdio.h>
#include <string.h>

// 声明函数 
void decode_phone_number(char *phone,unsigned char *arr);
void printf_uchar_arr(unsigned char *arr); 

int main()
{
	unsigned char arr[11]; 	// 必须要初始化 
	decode_phone_number("13212345678", arr);	// c语言不推荐像java那样直接return对象, 会报警告 
	                                            // 而是传入变量的指针, 由函数去操作指针(赋值或删除) 
	printf_uchar_arr(arr); 
	return 0;
}

void printf_uchar_arr(unsigned char *arr)
{
/*	int all_len = sizeof(arr);
	int single_len = sizeof(arr[0]); 
	int len = sizeof(arr)/sizeof(arr[0]); 
	printf("%d %d %d\n",all_len,single_len,len);*/ 
	int i = 0;	// 不支持在for里声明i 
	for(;i < 1000;i ++)
	{
		if(arr[i] == 0)
		{
			// 貌似也不能通过sizeof的方式获得数组的长度, 只能通过判断
			// arr[i] == 0的时候认为数组已经读完了, 
			// c和c++不存在索引越界, 如果遍历的时候i一直增加, 那么内存就会分配出对应的内存值 
			printf("len=%d",i); 
			break; 
		} 
		printf("arr[%d]=%02x\n",i,arr[i]); 
	} 
} 

// 解析手机号码 
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
