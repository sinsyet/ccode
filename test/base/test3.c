#include <stdio.h>
#include <stdlib.h>

void get_space(int *p)
{
	int *i = malloc(sizeof(int) * 10);
	p = i;
}
void get_space2(int **p)
{
	int *i = malloc(sizeof(int) * 10);
	*p = i;	
}
void main()
{
	// 不能写成int* p1,p2;
	int *p1, *p2;
	printf("p1: %p,p2: %p\n",p1,p2);
	get_space(p1);
	get_space2(&p2);
	printf("p1: %p,p2: %p\n",p1,p2);
}
