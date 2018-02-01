#include <stdio.h>
#include <string.h>

void main()
{
	char str[] = "hello, world i,am ygx";
	char *p;
	p = strtok(str," ");
	printf("%s\n",p);
	
	while((p = strtok(NULL,", ")) != NULL)
	{
		printf("%s\n",p);
	}

	printf("str:%s",str);
}
