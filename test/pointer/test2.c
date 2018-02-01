#include <stdio.h>

void main()
{
	// 二重指针
	int a = 3;
	int b = 8;
	int *p = &a;
	int **q;
	q = &p;
	**q = 10;
	*q = &b;
	**q = 5;
	p = &b;
	*p = 9;
	printf("a=%d\tb=%d\n",a,b);
	// **q = 10 -> a = 10;
	// *q = &b, **q = 5 -> b = 5;
	// p = &b,*p = 9;  -> b = 9；
	// a = 10; b = 9;
	/*
		a=10	b=9
	*/
}
