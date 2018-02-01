#include <stdio.h>

void cat_say()
{
	printf("miao miao\n");
}

void dog_say()
{
	printf("wang wang\n");
}

void say(void (*voice)())
{
	voice();
}

void main()
{
	int i;
	int flag = 1;
	whw:
	while(flag)
	{
		scanf("%d",&i);
		switch(i)
		{
			case 0: say(&dog_say); break;
			case 1: say(&cat_say); break;
			default: flag = 0; break;
		}
	}

	printf("finish\n");
}
