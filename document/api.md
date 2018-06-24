#### 字符串处理

size_t strlen(char *str);	// 返回字符串的长度(不包含0)

size_t strcat(char *str1, const char *str2); // s2拼接到s1后面,  返回新的长度

size_t strncat(char *str1, const char *str2, size_t count); 同上,只是说限制了拼接的s2字符个数

int strcmp(const char *str1, const char *str2); // 字典顺序比较, == 0 表示字符串相等, -1 str1小于str2, 1 str1 大于str2

strncmp(const char *s1, const char *s2, size_t count), 只比较指定数量的字符

strcpy(char *s1, const char *s2)	// 将s2的内容拷贝到s1; 从index 0开始; 主要用于初始化后的赋值
strncpy(s1, s2, 3); // 从s1的index0开始, 从s2拷贝3个字符

sprintf(char *s, char *format, ...);// 格式化字符串, 将格式化后的字符串输出到第一个参数指定的字符串中去

itoa();	// 不是标准的c语言库函数, 在windows有, linux没有;
		// 用sprintf();替代;
atoi();	// 标准c函数, str 2 int 

sscanf(char *s, char *format, ...); 从字符串中提取format数据

const char* strchr(s, char c);	// 返回找到的第一个指针地址

const char* strstr(char *s, char *str);

char* strtok(char *s, char *ss), 按ss分割字符串, strtok第一个调用的时候, 第一个参数是字符串, 第二次调用传NULL, 则会沿用上次的字符串继续切割 

<stdlib.h>
int atoi(char *num_s);	// 字符串数字转为整数
atof
atol