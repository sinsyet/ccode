#include <stdio.h>

// rewind， 将读写指针切换到开头; 
// 等价于： fseek(fp,0,SEEK_SET);
void main()
{
	FILE *fp = fopen("frwind.txt","w+");
	if(fp == NULL)
	{
		printf("open file err\n");
		return;
	}

	fprintf(fp,"hahaha,name:%s\tage:%d\tsex: %c","ygx",26,'m');
	rewind(fp);
	char buf[64];
	char ch;
	int index = 0;
	// fscanf(fp,buf);
	while((ch = fgetc(fp))!=EOF)
	{
		buf[index++] = ch;
	}

	printf("%s\n",buf);
	fclose(fp);
}
