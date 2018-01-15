#include <stdio.h>
#include <string.h>

struct people
{
	char *name;
	int age;
	char sex;
};

void main()
{
	struct people ygx = {"ygx",26,'M'};
	struct people zxm;
	strcpy(zxm.name,"zxm");
	zxm.age = 21;
	zxm.sex = 'F';
	printf("%s, %d, %c\n",ygx.name,ygx.age,ygx.sex);	
	printf("%s, %d, %c\n",zxm.name,zxm.age,zxm.sex);
	// 不能通过zxm.name 访问成员
}
