#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define LEN 5

struct student
{
	int id;
	char pname[10];	 // ���ﲻ����char *pname��, ��Ϊ����ʾ��ֻ���ַ����׸��ַ����ڴ��ַ, �����������ַ���������ڴ��ַԽ��, ���³������ 
	int score;
} /* *stus[LEN]*/ **stus;
// student *stus[LEN]	// ָ������, ���鱣�����student *��������
// student (*stus)[LEN] // ����ָ��, stus��һ��ָ�����, ����������������� student x[LEN], Ԫ�س���ΪLEN��student������
// 	* ����ָ��ȼ���ָ������
//	* ����ָ��ȼ��ڶ�ά���� 


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
