#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
有5个字符串，首先将它们按照字符串中的字符个数由小到大排列，
再分别取出每个字符串的第三个字母合并成一个新的字符串输出（若少于三个字符的输出空格）。要求：利用字符串指针和指针数组实现。

*/

#define LEN 5

char **s;

void init_arr()
{
	// 申请内存空间 
	s = (char**)malloc(sizeof(char*) * LEN);
	
	// 初始化赋值
	srand(time(NULL));
	char *str;
	int i = 0, j = 0;
	int len;
	char tmp; 
	for(; i < LEN; i++)
	{
		// 随机获取生成的字符串的长度			
		len = rand() % 10 + 2;	// 字符串长度: 2 ~ 12
		str = (char*)malloc(sizeof(char) * len + 1);	// len + 1, len个字符串, 1个'\0' 位 
		for(j = 0; j < len; j++)
		{
			tmp = (rand() % 2 == 0) ? 'A' : 'a'; 
			str[j] = tmp + rand() % 25; 
		} 
		str[j] = '\0';
		s[i] = str; 
	}
}

void printf_str_arr()
{
	int i = 0;
	for(; i < LEN; i ++)
	{
		printf("%s ",s[i]);
	} 
	printf("\n"); 
}

int comparator(char *s1, char *s2)
{
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2); 
	if(len1 > len2) return  1;
	if(len1 < len2) return -1;
	return 0; 
}
// swap 函数就算不是在主函数中调用, 也必须写在调用者前面, 
void swap(char **v1, char **v2)
{
	char *tmp =  *v1;
	// v1 = *v2;	// error, because of v1 is type of char **, *v2 is type of char * 
	*v1 = *v2;
	*v2 = tmp; 
} 
void str_sort(int (*compare)(char *s1,char *s2))
{
	// 插入排序;
	int i = 1, j = 0;
	char *tmp; 
	for(; i < LEN; i ++)
	{
		// 小到大 
		tmp = s[i];
		// tmp 大于 s[i - 1],则进入下一次循环 
		if(compare(tmp,s[i - 1]) >= 0) 
		{	
			continue;
		} 
		j = i - 1; 
		while(j >= 0 && (compare(tmp,s[j]) < 0)) 
		{
			// swap(&s[j], &tmp); // 这个搞错啦, 是将元素后移动,并不是和tmp交换 
			swap(&s[j], &s[j + 1]);	
			j --; 
		} 
		s[j + 1] = tmp; 
	} 
}

void merge(char *ss)
{
	int i = 0;
	for(; i < LEN; i ++)
	{
		ss[i] = strlen(s[i]) >= 3 ? s[i][2] : ' '; 
	}
	ss[i] = '\0'; 
} 

void main()
{
	init_arr();
	printf_str_arr();
	// printf("%u\n",comparator("len","ss"));
	printf("-------------------------------------\n"); 
	str_sort(&comparator);
	printf_str_arr(); 
	char str_arr[6]; 
	merge(str_arr);
	printf("merge: %s len:%u\n",str_arr,strlen(str_arr)); 
}
