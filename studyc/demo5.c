#include <stdio.h>

void main()
{
	// 
	printf("hello"); 
	putchar('\015');	// �س��ͻ���	
	printf("0,");
	// ȫ�������������hahao, ԭ����hello�����, �س�, ��굽��|hello, ������haha��ʱ��, �����hell 
	putchar('\n');
	putchar('\b');
	putchar('Y'); 
	
	char a,b,c;
	a = getchar();
	b = getchar();
	c = getchar();
	printf("%c,%c,%c",a,b,c); // ����Ҳ�����������ַ��� 
}
