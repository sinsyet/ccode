#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 删除字符串中的空格

typedef struct chr_frag chr_frag;

struct chr_frag
{
	int start_p;
	size_t len;
};

void strscpy(const char *src, char *dst, int src_start_p, int dst_start_p,size_t len)
{
	int i =  0;
	for(; i < len; i++)
	{
		*(dst + dst_start_p + i) = *(src + src_start_p + i); 
	} 
} 

void move(char *arr, int src, int dst, size_t m_len)
{
	size_t str_len = strlen(arr);
	if(src < 0 || dst < 0)
	{
		printf("%s is invalid arguement\n"); 
		return; 
	} 
	if(str_len < dst + m_len)
	{
		// 
		printf(" arr index out of Bounds\n"); 
		return; 
	} 
	
	// create a temp array;
	char tmp_arr[m_len];
	strscpy(arr,tmp_arr,src,0,m_len);
	strscpy(tmp_arr,arr,0,dst,m_len); 
	// void strscpy(const char *src, char *dst, int src_start_p, int dst_start_p,size_t len)
}

int indexof(char *arr, int start_p,char c)
{
	size_t len = strlen(arr);
	int i = start_p;
	for(; i < len; i++)
	{
		if(*(arr + i) == c)
		{
			return i;
		}
	}
	
	return -1;
} 

chr_frag *indexofchrs(char *arr, int start_p, char c)
{
	// 字符串的长度 
	size_t len = strlen(arr);
	// 起始索引 
	int i = start_p;
	// 标签, 标记是否发现指定字符 
	int flag = 0;
	// 结果结构体 
	chr_frag *r = NULL;
	
	for(; i < len; i++)
	{
		if(*(arr + i) == c)
		{
			if(!r)
			{
				r = malloc(sizeof(chr_frag));
				r->start_p = i;
				r->len = 1; 
			}
			else 
			{
				r->len ++; 
			} 
		}
		else if(r) 
		{
			break;
		}
	}
	
	return r;
}

void delete_space_word(char *arr)
{
	size_t len = strlen(arr); 
	int move_src;
	int move_dst;
	size_t m_len; 
	while(1)
	{	
		chr_frag *f = indexofchrs(arr,0,' ');
		if(!f) 
		{
			return;
		}
		// void move(char *arr, int src, int dst, size_t m_len)
		move_src =  f->start_p + f->len;
		move_dst =  f->start_p;
		m_len =  len - f->start_p - f->len;
		printf("%d\t%d\t%u\n",move_src,move_dst,m_len);
		move(arr,move_src,move_dst,m_len);
		unsigned int i = move_dst+m_len;
		for(; i < len; i++)
		{
			*(arr + i) = '\0';
		} 
		len = move_dst+m_len; 
		// *(arr+move_dst+m_len+1) = '\0'; 
	}
}

void main()
{
	char arr[] = "hello  world  p "; 
	delete_space_word(arr);
	printf("%s\n",arr);	
} 

void main_test_move()
{
	// void move(char *arr, int src, int dst, size_t m_len)
	char arr[] = "hell world";
	move(arr,5,2,5);
	printf("%s\n",arr);
	// heworldrld
} 

void main_index()
{
	// int indexof(char *arr, int start_p,char c) 
	int index = indexof("hello world",3,'l'); 
	int index2 = indexof("hi",0,'0');
	printf("index: %d, index2: %d\n",index,index2);
	// index: 3, index2: -1
}

void main_test_indexofchrs()
{
	// chr_frag *indexofchrs(char *arr, int start_p, char c);	
	chr_frag *f = indexofchrs("yy hello  world",3,' ');
	printf("start_p: %d\tlen:%u\n",f->start_p,f->len); 
	// start_p: 8      len:2
	
	chr_frag *f2 = indexofchrs("yy hello  world",0,'0');
	if((f2)==NULL)
	{
		printf("f2 is NULL");
	}
	else 
	{
		printf("f2 not is NULL");
	}
	// f2 is NULL
}
