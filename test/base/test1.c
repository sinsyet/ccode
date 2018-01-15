#include <stdio.h>
// 这里的参数是回调函数；
// void (*callback)(int,int) 等价于: void (*callback)(int a, int b)
void key_event(void (*callback)(int a,int b))
{
	int keycode;
	while(1)
	{
		scanf("%d",&keycode);

		if(keycode < 0) break;
		
		if(callback)
		// if(callback != NULL)
		{
			printf("callback not NULL\n");
			callback(keycode,1);
		}
		else
		{
			printf("callback is NULL\n");
		}
	}
	// scanf("%d");
}

void keycode_callback(int key,int action)
{
	printf("key: %d, action:%d \n",key,action);
}
void main()
{
	key_event(keycode_callback);
//	key_event(NULL); // 会输出段错误
//	printf("%d",!NULL);
}
