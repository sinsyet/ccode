#include <stdio.h>
#include "str_test.h"

void main()
{
	char *str = "how now, wo ai ni?";
	char *delim = "ow";
	int count = substring(str,delim);	
	printf("count: %d\n",count);
}
