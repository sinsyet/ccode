#include <stdio.h>

void main()
{
	int c1,c2;
	c1 = 289;
	c2 = 322;
	printf("%c,%c\n",c1,c2);	// 289 -> 100100001 -> 100001 -> 33 -> !, 322 -> B 
	printf("%d,%d\n",c1,c2);
	printf("%d",sizeof(char)); 
	printf("----------------------");
	putchar('\015'); 
}
