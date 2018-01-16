#include <stdio.h>
#include <string.h>

// 字符替换。要求用函数replace将用户输入的字符串中的字符t(T)都替换为e(E)，并返回替换字符的个数。

int replace(char *str, char t, char e)
{
	int count = 0;
	// 疑问: unsigned int是否可以做正常的运算? 
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
	// 疑问: unsigned int是否可以做正常的运算? 
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
	// 疑问: unsigned int是否可以做正常的运算? 
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
	// 疑问: unsigned int是否可以做正常的运算? 
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
	// char *str = "hello world"; // 出错, 因为 char *str = "hello world" 指向的字符串内存地址是常量区的, 字符序列可读不可写;
								  // 下面的replace函数涉及到了修改这个字符串,所以程序会报错
	// replace("hello world",'l','k');// 等价于将常量的字符序列的内存地址赋值给replace函数的形参, 同上, 其指向的内存地址一样的
									  // 是可读不可写 
	char str[] = "hello world"; 
	int count = replace4(str,'l','k'); 
	printf("%s, %d\n",str,count);
	// hekko workd, 3 
}
  
