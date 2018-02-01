#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	char *s, *p;
	int len = 10;
	s = calloc(len,sizeof(char));
	p = s;
	
	while((*p = getchar())!='q')
	{
		putchar(*p);
//		printf("%p\n",p);
		p++;
		/* 其实这里的p++一直在增长 */
	}
}

void main1()
{
	char *str = calloc(10,sizeof(char));
	printf("str1: %s\t%lu\n",str,strlen(str));
	memset(str+1,'A',3);
	// memset(str,'A',3);
	printf("str:%s\n",str);
	free(str);
	/*
str1: 	0
str:

申请的内存地址里， 默认值是0
strlen的返回值是size_t，size_t在64位系统里是long unsigned int；
	*/
}
