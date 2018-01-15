#include <stdio.h>
#include "str_test.h"
#include <stdlib.h>
#include <time.h>

#define LEN 10

void str_test2()
{
	srand(time(NULL));
	char *str = malloc(sizeof(char) * LEN);
	
	int i = 0;
	for(; i < LEN; i ++)
	{
		str[i] = 65 + rand() % 10;
	}
	printf("str: %s\n",str);
	// ------- 
	char *s = strstr(str,"A");
	printf("sp: %p, s: %s; strp: %p, str: %s\n",s,s,str,str);
	free(str);
	str = NULL;
	printf("sp: %p, s:%s; strp: %p, str: %s\n",s,s,str,str);
	/*
		str: HHAEICAGEJ
		sp: 0x18b8012, s: AEICAGEJ; strp: 0x18b8010, str: HHAEICAGEJ
		sp: 0x18b8012, s:; strp: (nil), str: (null)
		
		PS:
		当str被free后, s指向的内存地址不再有意义;
	*/
}

void str_test()
{
	char *str = "fuck you cks";
	char *s = strstr(str,"ck");
	printf("strp:%p sp:%p str:%s s:%s\n",str,s,str,s);
	// strp:0x4006e4 sp:0x4006e6 str:fuck you cks s:ck you cks
	// s来自于str; 类似于返回了索引
}

void main()
{
	char *str = "hello，world,fuck you";
	int count = substring(str,"l");
	
	// 3 hello，world,fuck you
	printf("%d %s\n",count,str);
	// str的内容没有改变
	// str_test();
	str_test2();
}

