#include <stdio.h>

struct STU_2
{
	int aa;
	long data;
	long age;
	char name[20];
	/*
48
2： 48

*/
};

typedef struct STU_2 student;

// typedef char* ch;

void main()
{
	student s = {23,9988};
	student *y = &s;
	printf("%lu\n",sizeof(s));
	printf("2： %lu\n",sizeof(student));
	/*
		16
		2： 16
	*/

	printf("s.age: %ld\n",s.age);
	printf("y->age:%ld\n",y->age);
	printf("(*y).age:%ld\n",(*y).age);
	/*
	s.age: 23
	y->age:23
	(*y).age:23

	*/
}

void main1()
{
	// struct size;
	printf("long - size:%lu\n",sizeof(long));
	printf("long long - size:%lu\n",sizeof(long long));
	printf("double - size:%lu\n",sizeof(double));
	printf("float - size:%lu\n",sizeof(float));
	/*
		char - size:1
		short - size:2
		int - size:4
		
		unsigned char - size:1
		unsigned short - size:2
		unsigned int - size:4

		long - size:8
		long long - size:8
		double - size:8
		float - size:4
	*/
}
