#include <stdio.h>

//  读取并打印一个文件的内容
void main(int argc, char *argv[])
{
//	printf("argv[1]: %s",argv[1]);
	FILE *fp = fopen(argv[1],"r");
	
	if(fp == NULL)
	{
		printf("open file err\n");
		return;
	}
	char buf[1024];
	while(NULL != fgets(buf,sizeof(buf),fp))
	{
		printf("%s",buf);
	}
}
