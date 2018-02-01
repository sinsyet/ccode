#include <stdio.h>

void main()
{
	const int i = 12;
	const int *p = &i;	// 如果这里的int *p不加const,
				// 编译器在编译的时候会报警告,表示i仍然可以通过12来改变
				// 将int *p 也用就不会报警告了
	// *p = 14;
	printf("i:%p, %d\n",&i,i);
	printf("p:%p, %d\n",p,*p);
}
