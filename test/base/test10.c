#include <stdio.h>
#include <string.h>

// �ַ��滻��Ҫ���ú���replace���û�������ַ����е��ַ�t(T)���滻Ϊe(E)���������滻�ַ��ĸ�����

int replace(char *str, char t, char e)
{
	int count = 0;
	// ����: unsigned int�Ƿ����������������? 
	size_t len = strlen(str); 
	int i = 0;
	
	for(; i < len; i ++)
	{
		if(str[i] == t)
		{
			str[i] = e;
			count ++; 
		} 
	}
	
	return count; 
} 

/// [Error] assignment of read-only location '*(str + (sizetype)((long long unsigned int)i * 1ull))'
int replace2(/*const*/ char *str, char t, char e)
{
	int count = 0;
	// ����: unsigned int�Ƿ����������������? 
	size_t len = strlen(str); 
	int i = 0;
	
	for(; i < len; i ++)
	{
		if(str[i] == t)
		{
			str[i] = e;
			count ++; 
		} 
	}
	
	return count; 
}
/// [Error] assignment of read-only location '*(str + (sizetype)((long long unsigned int)i * 1ull))' 
int replace3(char /*const*/ *str, char t, char e)
{
	int count = 0;
	// ����: unsigned int�Ƿ����������������? 
	size_t len = strlen(str); 
	int i = 0;
	
	for(; i < len; i ++)
	{
		if(str[i] == t)
		{
			str[i] = e;
			count ++; 
		} 
	}
	
	return count; 
}
// hekko workd, 3
int replace4(char *const str, char t, char e)
{
	int count = 0;
	// ����: unsigned int�Ƿ����������������? 
	size_t len = strlen(str); 
	int i = 0;
	
	for(; i < len; i ++)
	{
		if(str[i] == t)
		{
			str[i] = e;
			count ++; 
		} 
	}
	
	return count; 
}  

void main()
{
	// char *str = "hello world"; // ����, ��Ϊ char *str = "hello world" ָ����ַ����ڴ��ַ�ǳ�������, �ַ����пɶ�����д;
								  // �����replace�����漰�����޸�����ַ���,���Գ���ᱨ��
	// replace("hello world",'l','k');// �ȼ��ڽ��������ַ����е��ڴ��ַ��ֵ��replace�������β�, ͬ��, ��ָ����ڴ��ַһ����
									  // �ǿɶ�����д 
	char str[] = "hello world"; 
	int count = replace4(str,'l','k'); 
	printf("%s, %d\n",str,count);
	// hekko workd, 3 
}
  
