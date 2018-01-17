#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>
#include <math.h>

struct people
{
	char name[10];
	int age; 
};

/*
ʵ��ģ���Ʊ�ĳ�����ƣ��������6�����֣����û���������ֽ��бȽϣ���������ͬ�����ָ���
��ʹ�ö�̬�ڴ���䣩��
*/
#define LEN 6
char *nums = NULL; 
void create_num()
{
	nums = (char*)malloc(sizeof(char) * (LEN + 1)); 
	int i = 0;
	srand(time(NULL));
	char tmp; 
	for(;i < LEN; i++)
	{
		while(1)
		{
			tmp = rand() % 9 + 48; 
			if(!strchr(nums,tmp))
			{
			 	 nums[i] = tmp;
				 break; 
			}	 
		}
	}
	nums[i] = '\0';
}

int get_valid_num_count(int num)
{
	// int max = 0x7fffffff; // 2147483647
	int max_ten = 1000000000;
	int len = 10; 
	int tmp = 0; 
	while(len >= 0)
	{
		tmp = num / (max_ten / pow(10,10 - len));
		if(tmp)	// tmp��Ϊ0 
		{
			break; 
		} 
		len --; 
	}
	return len; 
} 

char *int_2_str(int num)
{
	// ����ת��Ϊ�ַ���
	// �����м�λ��Ч���� 
	int count = get_valid_num_count(num);
	unsigned int max_ten1 = pow(10,count);
	unsigned int max_ten2 = pow(10,count - 1);
	printf("max_ten: %u\n",max_ten1); 
	
	char *str = malloc(sizeof(char) * (count + 1));
	char zero = '0';
	int c = 0;
	int i = 0; 
	for(; i < count; i++)
	{
		// 123456
		// 123456 % 1000000  -> 123456 / 100000 -> 1
		// 123456 % 10 -> 23
		// c = (123456 % (int)(1000000 / pow(10,i))) / (int)(100000 / pow(10,i));
		c = (num % (int)(max_ten1 / pow(10,i))) / (int)(max_ten2 / pow(10,i));
		str[i] = zero + c; 
	}
	str[i] = '\0';
	return str; 
} 
// ȥ�� 
char *filter_repeat(char *str)
{
	int i = 0;
	
	size_t len = strlen(str); 
	char s[len];
	char no_repeat_index = 0; 
	char c_tmp; 
	for(; i < len; i++)
	{
		c_tmp = str[i]; 
		if(strchr(s,c_tmp) != NULL) continue;
		s[no_repeat_index++] = c_tmp; 
	}
	s[no_repeat_index] = '\0';
	size_t no_repeat_len = strlen(s); 
	char *result = malloc(sizeof(char) * (no_repeat_len + 1));
	strncpy(result,s,no_repeat_len);
	result[no_repeat_len] = '\0';
	return result; 
}
 
int find_same(char *delim)
{
	// nums
	size_t len = strlen(delim); 
	int i = 0;
	char c; 
	int same_count = 0;
	for(; i < len; i++)
	{
		c = delim[i];
		if(strchr(nums,c))
		{
			printf("%c ",c);
			same_count ++;
		}
	}
	return same_count;
}
 
void main()
{
	create_num();
	// printf("%s %u",nums,strlen(nums)); 
	printf("input num: ");
	int num = 0; 
	scanf("%d",&num);
	int count = get_valid_num_count(num);
	printf("num:%d, count:%d\n",num,count); 
	// num:100000001, count:9
	char *istr = int_2_str(num); 
	printf("istr: %s\n",istr);
	char *ss = filter_repeat(istr); 
	printf("ss: %s\n",ss);
	/*
		istr: 90234432
		ss: 90234
	*/
	int same_count = find_same(ss); 
	printf("nums: %s, inputNum: %d, same_count:%d\n",nums,num,same_count);
	printf("-------------------------------\n");
	
	// �ṹ������ָ�ֵ�ķ��� 
	struct people zs = {"xgy",25};
	printf("zs.name:%s, zs.age:%d\n",zs.name,zs.age);
	// struct people *ls = (struct people*)malloc(sizeof(struct people*));
	// �������������ķ���������struct�����
	struct people ls; 
	strcpy(ls.name,"Json");
	ls.age = 26;
	printf("ls.name:%s, ls.age:%d\n",ls.name,ls.age);
		
	free(nums);
	free(istr);
	free(ss);
}

