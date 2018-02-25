#include <stdio.h>

// 序列化一个结构体
struct STU
{
	int age;
	char name[20];
	char sex;
};

void main()
{
	struct STU ygx = {26,"ygx",'m'};
	// 文件权限: w+ 可读可写; 如果文件不存在，则创建文件；如果存在，则截断
	FILE *fp = fopen("cache.txt","w");	
	if(!fp)
	{
		printf("open file err");
		return;
	}
	
	size_t c = fwrite(&ygx,sizeof(struct STU),10,fp);
	printf("count: %ld\n",c);
	fclose(fp);	
}
