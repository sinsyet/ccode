#include <stdio.h>

#define LEN 11

void decrypt();
int is_leap_year(int year);
void decrypt_leap_year_code(int code,char *text);

void decrypt(unsigned char *src, char *dst)
{
	int i = 0;
	for(;i < LEN;i ++)
	{
		dst[i] = (char)~src[i];
	}
}

// 1, leap year; 0, not leap year; -1 invalid year number
int is_leap_year(int year)
{
	if(year < 0) return -1;
	if(year % 400 == 0) return 1;
	if((year % 4 == 0) && (year % 100 != 0)) return 1;
	return 0;
}

void decrypt_leap_year_code(int code,char *text)
{
	if(code < 0)
	{
		text = "invalid year number";
		return;
	}
	text = code > 0 ? "leap year" : "not leap year";
}
