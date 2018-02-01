#include <stdio.h>
#include <string.h>

union ITEM
{
	char name[20];
	int age;
};

typedef union ITEM person;

void main()
{
	person p /* = {"ygf",26}*/;	// union can‘t init by this way
	p.age = 26;
	strcpy(p.name,"ygf");
//	p.age=26;
	printf("%ld\t%ld\n",sizeof(p),sizeof(person));
	printf("name:%s\tage:%d\n",p.name,p.age);
/*
	name:ygf	age:1719166841
*/
}
