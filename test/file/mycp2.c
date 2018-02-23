#include <stdio.h>

// 用fgetc和fputc复制文件
void main(int argc, char *argv[])
{
	char *src = argv[1];
	char *dst = argv[2];
	
	FILE *fp_src = fopen(src,"r");
	if(!fp_src)
	{
		// open src file err
		printf("open src file err\n");
		return;
	}

	FILE *fp_dst = fopen(dst,"w");
	if(!fp_dst)
	{
		printf("create dst file fail\n");
		fclose(fp_src);
		return;
	}

	char ch;
	while((ch = fgetc(fp_src)) != EOF)
		fputc(ch,fp_dst);

	fclose(fp_src);
	fclose(fp_dst);
}
