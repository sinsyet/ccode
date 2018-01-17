#include <stdio.h>
#include <math.h>

void main()
{
	
	int c = 123456 % 100000;
	int i = 0; 
	for(; i < 6; i++)
	{
		c = (123456 % (int)(1000000 / pow(10,i))) / (int)(100000 / pow(10,i));
		printf("%d ",c); 
	}
	//printf("%d\n",c); 
}


