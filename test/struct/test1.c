#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int create_num()
{
	srand(time(NULL));
	return rand() % 100; 
}

void main()
{
	// ����һ��1-100����, 
	// �Ӽ���¼��һ����, ƥ���Ƿ�ɹ�, 
	//    �ɹ�����ʾƥ��ɹ�����ʾ��������; 
	//    ʧ���������
	int num = create_num(); 
	int i;
	int count = 0; 
	while(1)
	{
		printf("input num:");
		scanf("%d",&i);
		if(i == num)
		{
			printf("congratulation, right, guess count:%d\n",count);
			break;
		} 
		
		if(i > num)
		{
			printf("\tlarge\n"); 
		}else 
		{
			printf("\tlower\n");
		} 
		count ++;
	} 
	printf("game over"); 
}
