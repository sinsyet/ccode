#include <stdio.h>
#include <string.h>

void change_str(char *s);
void change_str2(char *s);

int  main()
{
	char s[10] = "hello";
	// printf("%d,%d\n",sizeof(s),strlen(s));
	printf("1-- %s\n",s);
	change_str(s);
	printf("2-- %s\n",s);
	change_str2(s);
	printf("3-- %s\n",s);
	return 0;
	/*
		1-- hello
		2-- hel
		3-- hello
	*/
}

void change_str(char *s)
{
//	printf("sizeof=%d,strlen=%d",sizeof(s),strlen(s));
	*(s+3) = '\0';
}

void change_str2(char *s)
{
	*(s+3)='l';
}
