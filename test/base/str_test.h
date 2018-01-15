#include <stdio.h>
#include <string.h>

// 计算子字符串出现的次数
int substring(const char *str, char *delim)
{
	// 初始化一个int类型的计数变量;
	int count = 0;
	
	while(str = strstr(str,delim))
//	while(strstr(str,delim))
	{
		str ++;
		count ++;
	}

	// 返回count, 表示在target字符串中有count个delim
	return count;
}
/*
	substring 总结：
	1. const char *str表示的是char类型的指针变量，它的地址值不可修改，但是它所表示的值可以修改； 因此下面用str = strstr(str,delim)和str ++可以通过编译和正常运行
	
	2. while(str = strstr(str,delim))表示从str里获取delim的指针， 赋值给str,
并且当str不为NULL时满足条件表达式;

	3. str ++; str为char类型的指针变量， 它保存的是字符串的首个字符的内存地址; str ++相当于是将指针切换到下一个字符的内存地址; c语言中，字符串以'\0'为结束符号

	4. strstr(str,delim),参数中的str并不会被裁剪, 返回值是一个新的字符串指针
*/
