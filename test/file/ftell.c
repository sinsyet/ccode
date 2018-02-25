#include <stdio.h>

void main()
{
	FILE *fp = fopen("ftell.txt","w+");
	if(!fp)
	{
		printf("open file err\n");
		return;
	}

	int i = fputs("xixixi",fp);
//	fclose(fp);
	printf("%d %ld\n",i,ftell(fp));
	fclose(fp);
}
