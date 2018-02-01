#include <stdio.h>

int a;
int b;

void foo()
{
	printf("%d",a);
}

void main()
{
	a = 9;
	foo();
}
