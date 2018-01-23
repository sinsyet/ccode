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
	// 生成一个1-100的数, 
	// 从键盘录入一个数, 匹配是否成功, 
	//    成功则显示匹配成功并提示猜数次数; 
	//    失败则继续猜
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
