#include <stdio.h>

void main()
{
	int i = 1;
	int* ii = &i;
	printf("%p, %d\n",ii,*ii);
	int* i1 = ii;
	printf("%p, %d\n",i1,*i1);
}
