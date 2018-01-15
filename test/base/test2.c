#include <stdio.h>

void main()
{
	int i = 340;
	int *p_i = &i;
	int **p_p_i = &p_i;
	printf("%d,%d,%d\n",i,*p_i,**p_p_i);
	printf("i:%p,p_i:%p,p_p_i:%p\n",&i,&p_i,&p_p_i);
	printf("%d,%p，%p\n",i,p_i,p_p_i);
	/*
		340,340,340
		i:0x7ffce15629ec,p_i:0x7ffce15629f0,p_p_i:0x7ffce15629f8
		340,0x7ffce15629ec，0x7ffce15629f0

	*/
}
