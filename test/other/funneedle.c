#include <stdio.h>


int add(int x,int y)
{
	return x + y;
}

void main()
{
	int (*a)(int x,int y) = add;
	printf("a: %d\n",a(3,4));
}
