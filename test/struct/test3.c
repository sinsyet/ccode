#include <stdio.h>


#define RED 0
#define GREEN 1
#define BLUE 2

enum COLOR
{
	RED, GREEN, BLUE,BLACK
};

void main()
{
	enum COLOR c = 13;
	printf("%d\n",c);
}

void main1()
{
	enum COLOR c = 1;	
	// printf("%s\t%d\n",c,c);
	// 编译器报warning:c is type unsigned int
}
