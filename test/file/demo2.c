#include <stdio.h>

void main(int argc, char *argv[])
{
	printf("argc: %d\n",argc);
	
	int i = 0;
	for(; i < argc; i++)
	{
		printf("%s\n",argv[i]);
	}
	/*
	ygx@ygx-ubuntu:~/桌面/code/cc/ccode/test/file$ ./app fuck you zxm, zjx
argc: 5
./app
fuck
you
zxm,
zjx

指针数组 char *argv[]

	--> 等价于二重指针

数组指针 char (*p)[10]

	--> 等价于二维数组




	*/
}
