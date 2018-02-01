#include <stdio.h>

// 数组指针， 保存数组内存地址的指针

void main()
{
	char str[4][10] = {"Can","I","Fuck","You"};

	// 数组指针定义的含义是: 保存的是char类型的数组，这个数组的长度为10个	
	char (*p)[10];
	// p = &str;	// 错误的赋值方式; 因为指针保存的是char[10]的地址，所以只能将&str[0]赋值过去
	p = &str[0];
	printf("%p %s\t%p %s\t%p %s\t%p %s\n",(*p),(*p),*(p+1),*(p+1),*(p+2),*(p+2),*(p+3),*(p+3));
	/*
		0x7fffc2251c10 Can	0x7fffc2251c1a I	0x7fffc2251c24 Fuck	0x7fffc2251c2e You
	*/
}

void main1()
{
	int i_arr[10] = {1,2,3,4,5};
	int (*p)[10];
	p = &i_arr;
	printf("%p\t %d\t %d\n",p,(*p)[5],(*p)[4]);
	// 0x7ffd5e320d60	 0	 5

	int  i = 0;
	for(; i < 10; i++)
	{
		printf("%p %d\n",(*p),(*p)[i]);
	}
	/*
		0x7ffc0c2c5730 1
		0x7ffc0c2c5730 2
		0x7ffc0c2c5730 3
		0x7ffc0c2c5730 4
		0x7ffc0c2c5730 5
		0x7ffc0c2c5730 0
		0x7ffc0c2c5730 0
		0x7ffc0c2c5730 0
		0x7ffc0c2c5730 0
		0x7ffc0c2c5730 0
		// ×p指向的都是数组i_arr的地址值
	*/
}
