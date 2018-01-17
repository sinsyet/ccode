#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
��5���ַ��������Ƚ����ǰ����ַ����е��ַ�������С�������У�
�ٷֱ�ȡ��ÿ���ַ����ĵ�������ĸ�ϲ���һ���µ��ַ�������������������ַ�������ո񣩡�Ҫ�������ַ���ָ���ָ������ʵ�֡�

*/

#define LEN 5

char **s;

void init_arr()
{
	// �����ڴ�ռ� 
	s = (char**)malloc(sizeof(char*) * LEN);
	
	// ��ʼ����ֵ
	srand(time(NULL));
	char *str;
	int i = 0, j = 0;
	int len;
	char tmp; 
	for(; i < LEN; i++)
	{
		// �����ȡ���ɵ��ַ����ĳ���			
		len = rand() % 10 + 2;	// �ַ�������: 2 ~ 12
		str = (char*)malloc(sizeof(char) * len + 1);	// len + 1, len���ַ���, 1��'\0' λ 
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
// swap �������㲻�����������е���, Ҳ����д�ڵ�����ǰ��, 
void swap(char **v1, char **v2)
{
	char *tmp =  *v1;
	// v1 = *v2;	// error, because of v1 is type of char **, *v2 is type of char * 
	*v1 = *v2;
	*v2 = tmp; 
} 
void str_sort(int (*compare)(char *s1,char *s2))
{
	// ��������;
	int i = 1, j = 0;
	char *tmp; 
	for(; i < LEN; i ++)
	{
		// С���� 
		tmp = s[i];
		// tmp ���� s[i - 1],�������һ��ѭ�� 
		if(compare(tmp,s[i - 1]) >= 0) 
		{	
			continue;
		} 
		j = i - 1; 
		while(j >= 0 && (compare(tmp,s[j]) < 0)) 
		{
			// swap(&s[j], &tmp); // ��������, �ǽ�Ԫ�غ��ƶ�,�����Ǻ�tmp���� 
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
