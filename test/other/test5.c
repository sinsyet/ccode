#include <stdio.h>
#include <string.h>

void main()
{
//	char str[10];
// 	char *str;	// 指向的是野指针， 没有读写空间
	char tmp[] = "con";
	char *str = tmp;
	char *src = "hello";
	printf("%s\n",strcpy(str,src));
}
