#include <stdio.h>

// my cp
void main(int argc, char *argv[])
{
	char *src = argv[1];
	char *dst = argv[2];

	FILE *fp_src = fopen(src,"r");
	// 等价于fp_src == NULL
	if(!fp_src)
	{
		printf("open src file err\n");
		return;
	}	
	
	FILE *fp_dst = fopen(dst,"w");
	if(!fp_dst)
	{
		printf("open dst file err\n");
		fclose(fp_src);
		return;
	}

	char buf[1024 * 8];
	while(NULL != fgets(buf,sizeof(buf),fp_src))
		fputs(buf,fp_dst);
	
	fclose(fp_src);
	fclose(fp_dst);
}
