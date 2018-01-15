#include <stdio.h>
#include <string.h>

int substring(const char *str, char *delim)
{
	char *s = strstr(str,delim);
	int count = 0;
	while(str = strstr(str,delim))
	{
		if(str == NULL)
			break;
		printf("%s，%d\n",str,count);
		str ++;
		count ++;
	}
	return count;
}

void main()
{
	// const char *str = "fuck you tuck";
	// char *s = strstr(str,"ck");
	// printf("%s\n",s);
	// while(s = strstr(s,"ck"))
	// {
	// 	printf("%s\n",s);
	// 	s++;
	// }
	int count = substring("fuck you tuck","ck");
	printf("count: %d\n",count);
}


