#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define LEN 5

struct student
{
	int id;
	char pname[10];	 // 这里不能用char *pname来, 因为它表示的只是字符串首个字符的内存地址, 用它来保存字符串会造成内存地址越界, 导致程序崩溃 
	int score;
} /* *stus[LEN]*/ **stus;
// student *stus[LEN]	// 指针数组, 数组保存的是student *类型数据
// student (*stus)[LEN] // 数组指针, stus是一个指针变量, 它保存的数据类型是 student x[LEN], 元素长度为LEN的student型数组
// 	* 二重指针等价于指针数组
//	* 数组指针等价于二维数组 


typedef struct student student;

void stuff_stu(struct student *l_stu)
{
	// ygx = calloc(1,sizeof(struct student)); 
	// printf("input id: ");
	// scanf("%d",&(l_stu->id));
	printf("input name:");
	scanf("%s",l_stu->pname);	 
	printf("input score:");
	scanf("%d",&(l_stu->score)); 
} 
void stuff_stus()
{
	int i = 0;
	student *tmp;
	for(; i < LEN; i++)
	{
		tmp = malloc(sizeof(student*));
		stuff_stu(tmp); 
		tmp->id = i;
		stus[i] = tmp; 
	}
}
void printf_stu(struct student *stu)
{
	printf("id: %d \t pname: %s \t score: %d\n",stu->id,stu->pname,stu->score); 
} 

void printf_stus()
{
	int i = 0;
	for(; i < LEN; i++)
	{
		printf_stu(stus[i]); 
	}
}

int stu_cpm(student *src, student *dst)
{
	if(src->score > dst->score) return 1;
	if(src->score < dst->score) return -1;
	return 0; 
}

void stuscpm()
{
	int i = 1, j;
	student *tmp; 
	for(; i < LEN; i++)
	{
		tmp = *(stus + i);
		if(stu_cpm(tmp,*(stus + i - 1)) < 0)
		{
			// tmp < i - 1; 
			j = i - 1;
			while(j >= 0 && stu_cpm(tmp,*(stus + j)) < 0)
			{
				*(stus + j + 1) = *(stus + j);
				j --; 
			} 
			*(stus + j + 1) = tmp; 
		}
	}
}

void main()
{
	stus = calloc(5,sizeof(student*)); 
	stuff_stus();
	printf_stus();
	printf("---------------------------\n");
	stuscpm();
	printf_stus(); 
} 
