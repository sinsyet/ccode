#include <stdio.h>

void main()
{
	char buf[1024];
	FILE *fp = fopen("test.txt","r");
	
	if(fp == NULL)
	{
		printf("open file err");
		return;
	}
	
	
	fgets(buf, sizeof(buf),fp);
	printf("%s",buf);	
	
}
