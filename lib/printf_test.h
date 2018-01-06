#include <stdio.h>

void printf_gui(int len,char base_c,int run_type);
int min(int x,int y);
int abs(int i);
void printf_wave(int len,char base_c);
void printf_wave2(int len,char base_c);


void printf_gui(int len,char base_c,int run_type)
{
	// 共有len个字符
	char cc[len];
	// 初始化数组
	int i = 0;
	for(;i < len;i ++)
	{
		cc[i] = (run_type == 0) ? (base_c + i) : (base_c - i);
	}
	
	// 循环打印图形， 图形其实是一个len * len的正方形
	i = 0;
	int j = 0;
	int x,y;
	int square_len = len * 2 - 1;
	for(;i<square_len;i++)
	{
		printf("%10s"," ");
		j = 0;
		for(;j<square_len;j++)
		{
			x = (len - 1) - abs(len - 1 - i);
			y = (len - 1) - abs(len - 1 - j);
			printf("%c ",cc[min(x,y)]);
		}
		printf("\n");
	}
}

void printf_wave(int len, char base_c)
{
	char cc[len];
	int i = 0;
	int tmp;
	int cc_half = (len * 1.0f / 2 + 0.5f);
	for(;i < cc_half; i++)
	{
		cc[i] = base_c + i;
		cc[len - 1 - i] = base_c + i;
	}
	i = 0;
	int j = 0;
	int x,y;
	int square_len = len * 2 - 1;
	for(;i < square_len;i ++)
	{
		j = 0;
		printf("%10s", " ");
		for(;j<square_len;j++)
		{	
			x = (len - 1) - abs(len - 1 - i);
			y = (len - 1) - abs(len - 1 - j);
			printf("%c ",cc[min(x,y)]);
		}
		printf("\n");
	}
}

void printf_wave2(int len, char base_c)
{
	char cc[len];
	int i = 0;
	int tmp;
	int cc_half = (len * 1.0f / 2 + 0.5f);
	base_c = base_c - (cc_half - 1);
	for(;i < cc_half; i++)
	{
		cc[i] = base_c + i;
		cc[len - 1 - i] = base_c + i;
	}
	i = 0;
	int j = 0;
	int x,y;
	int square_len = len * 2 - 1;
	for(;i < square_len;i ++)
	{
		j = 0;
		printf("%10s", " ");
		for(;j<square_len;j++)
		{	
			x = (len - 1) - abs(len - 1 - i);
			y = (len - 1) - abs(len - 1 - j);
			printf("%c ",cc[min(x,y)]);
		}
		printf("\n");
	}
}
int min(int x,int y)
{
	return x > y ? y : x;
}

int abs(int i)
{
	return i > 0 ? i : -i;
}
