#include <stdio.h>

void main()
{
	// 
	printf("hello"); 
	putchar('\015');	// 回车和换行	
	printf("0,");
	// 全部输出的内容是hahao, 原因是hello输出后, 回车, 光标到了|hello, 再输入haha的时候, 替代了hell 
	putchar('\n');
	putchar('\b');
	putchar('Y'); 
	
	char a,b,c;
	a = getchar();
	b = getchar();
	c = getchar();
	printf("%c,%c,%c",a,b,c); // 换行也算是输入了字符的 
}
