#include <stdio.h>

struct STU
{
	int age;
	char name[20];
	char sex;
};

void main()
{
	FILE *fp = fopen("cache.txt","r");
	if(!fp)
	{
		printf("open file err\n");
		return ;
	}

	struct STU s;
	size_t st = 0;
	int count = 0;
/*	while(1){
		st = fread(&s,sizeof(struct STU),1,fp);
		printf("name: %s\nage: %d\nsex: %c\n",s.name,s.age,s.sex);
		if(!st)
		{
			break;
		}
		count ++;
		fseek(fp,sizeof(struct STU) * count,SEEK_CUR);
	}
*/
	int index = 0;
	do{
		fseek(fp,sizeof(struct STU) * index,SEEK_CUR);
		st = fread(&s,sizeof(struct STU),1,fp);
		printf("name: %s\nage: %d\nsex: %c\n",s.name,s.age,s.sex);
		index ++;
	}while(st > 0);
	
	fclose(fp);
}
