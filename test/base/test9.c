#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
2�����ܳ���:�ɼ����������ģ�ͨ�����ܳ���ת�������Ĳ��������Ļ�ϡ��㷨�������е���ĸת�������ĵ�4����ĸ,���磬A���E(a���e)��Z���D,����ĸ�ַ����䣻ͬʱ������ÿ�����ַ�֮�����һ���ո�
���磬Chinaת��������ΪG?l?m?r?e��
Ҫ���ں���change�������ĸת�����ں���insert��������ӿո���ָ�봫�ݲ�����
*/

#define ascii_a 97     
#define ascii_v 97 + 21
#define ascii_z 97 + 25
                  
#define ascii_A 65
#define ascii_V 65 + 21
#define ascii_Z 65 + 25

#define word_len 26

#define ascii_space 33

char *encry(const char *str)
{
	/*
		W -- > A
		v -- > Z
	*/
	/*
	int ascii_a = 97;
	int ascii_v = 97 + 21;
	int ascii_z = 97 + 25;
	
	int ascii_A = 65;
	int ascii_V = 65 + 21;
	int ascii_Z = 65 + 25;
	
	int ascii_space = 32;
	*/
	int len = (int)strlen(str);
	printf("len: %d\n",len);
	char *encry_str = (char*)malloc(sizeof(char) * (len+len/2));
	int i = 0, encry_char_index = 0;

	char tmp;
	
	for(; i < len; i ++)
	{
		tmp = str[i];
		if(
			(tmp >= ascii_a && tmp <= ascii_v) ||
			(tmp >= ascii_A && tmp <= ascii_V))
		{
			encry_str[encry_char_index] = tmp + 4;
		}
		else if(
		(tmp > ascii_v && tmp <= ascii_z) ||
			(tmp > ascii_V && tmp <= ascii_Z))
		{
			encry_str[encry_char_index] = tmp + 4 - word_len;
		}
		else
		{
			encry_str[encry_char_index] = tmp;
		}
		encry_char_index ++;
		if(!((encry_char_index + 1) % 2))
		{
			encry_str[encry_char_index++] = ascii_space;
		}		
	}
	return encry_str;
}

char *change(const char *str)
{
	int len = (int)strlen(str);
	printf("len: %d\n",len);
	char *s = (char*)malloc(sizeof(char) * len);
	
	int i = 0;
	char tmp;
	for(;i < len; i++)
	{
		tmp  = str[i];
		tmp = str[i];
		if(
			(tmp >= ascii_a && tmp <= ascii_v) ||
			(tmp >= ascii_A && tmp <= ascii_V))
		{
			s[i] = tmp + 4;
		}
		else if(
		(tmp > ascii_v && tmp <= ascii_z) ||
			(tmp > ascii_V && tmp <= ascii_Z))
		{
			s[i] = tmp + 4 - word_len;
		}
		else
		{
			s[i] = tmp;
		}
	}
	// �ַ���������'\0' �� 0��β; ����strlen���ô����ֵ�ʹ�ӡ�ַ�����ʱ�����ʾ�������� 
	s[i] = 0;
	return s;
}
/* ���������ַ������� */
void swap(char *src, char *dst)
{
	char tmp = *src;
	*src = *dst;
	*dst = tmp;
}

void swap2(char *src, char *dst)
{
	printf("before2: %s, %s\n",src,dst);
	char *tmp = src;
	src = dst;
	dst = tmp;
	printf("after2: %s, %s\n",src,dst);
	/*
		before: hello, world
		before2: hello, world
		after2: world, hello
		after: hello, world
		
		��ʵ���������src��dst���β��ϵı���������;
		����swap��, src��dst�е������Ѿ������ı�; �����ⲿ�����ߵ�ֵû�����ı� 
	*/ 
}

void swap3(char **src, char **dst)
{
	char *tmp = *src;
	*src = *dst;
	*dst = tmp;
	// ���������ֵ��ʵ��char* ���͵�����; �������ǵ�ֵַ; 
} 

// ÿ��һ���ַ�����һ���ո�; 
char *insert(char *s)
{
	size_t len = strlen(s);
	size_t str_len = len + len - 1; 
	// abcd -> 3
	// abcde -> 4
	// abcdef -> 5 
	char *str = malloc(sizeof(char) * str_len);
	int i = 0;
	int j = 0; 
	for(;i < len; i ++)
	{
		str[j ++] = s[i]; 
		if(i < len -1)
		{
			str[j ++] = ' ';	
		} 
	}
	
	return str; 
}

void main2()
{
	// char *s = encry("ChinZ34.09@a");
	// printf("s: %s\n",s);
	char a = 'a';
	char b = 'b';
	printf("before: %c, %c\n",a,b);
	swap(&a,&b);
	printf("after: %c, %c\n",a,b);
	printf("-----------------------------\n");
	char *s = "hello";
	char *s2 = "world";
	/* 
	printf("before: %s, %s\n",s,s2);
	swap2(s,s2);
	printf("after: %s, %s\n",s,s2);*/ 
	/*
		before: hello, world
		before2: hello, world
		after2: world, hello
		after: hello, world
	*/
	
	printf("before: %s, %s\n",s,s2);
	swap3(&s,&s2);
	printf("after: %s, %s\n",s,s2);
}

void main()
{
	char *str = "jack 134:0&@";
	char *s = change(str);
	printf("s: %s, len: %d\n",s,strlen(s));
	char *s2 = insert(s);
	printf("after-s: %s\ns2: %s\n",s,s2);
	
	free(s);
	free(s2); 
}
