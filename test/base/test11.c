#include <stdio.h>
#include <stdlib.h>
// 4、编写一个程序，输入星期，输出该星期的英文名。用指针数组处理。

char **day = NULL;

void init_day()
{
	if(day != NULL) {
		printf("-----");
		return;
	}
	day = malloc(sizeof(char*) * 8);
	day[0] = "Monday";
	day[1] = "Tuesday";
	day[2] = "Wednesday";
	day[3] = "Thursday";
	day[4] = "Friday";
	day[5] = "Saturday";
	day[6] = "Sunday";
	day[7] = "Unknown";
	printf("init over\n");
}
void printf_day(int date)
{
	// char **day = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday","Unknown"};
	init_day();
	if(date > 7 || date < 1)
	{
		date = 7;
	}
	else
	{
		date --;
	}
	char *today = day[date];
	printf("today is: %s\n",today);
}
void main()
{
	printf_day(-1);
}
