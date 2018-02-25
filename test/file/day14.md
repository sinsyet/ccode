#### C文件IO

* 文件类型:
	* stream文件(.word,.txt,...)
	* 设备文件: vga接口, 网口, 串口, usb; 操作系统都可以把它抽象为文件
	* c标准里文件操作,一般是指流文件
		* fopen()打开文件
		* fclose()关闭文件
		* fgets(); 从文件一次读一行
		* fputs();从文件一次写一行
		* f

* 案例:

	void main()
	{
		printf("hello world");
		// fflush(stdout);
		while(1);
		
		// 不输出;
		// 去掉while(1);或增加fflush(stdout)后, 会输出hello world;
		
	}

* 扩展:

程序运行时会打开stdin标准输入, stdout标准输出, stderr标准出错

scanf("%s",str);	// 从标准输入上取数据

键盘 -> 键盘驱动 -> stdin -> sacnf

printf -> stdout -> 显示终端 -> 显示屏

键盘驱动/显示终端驱动由系统厂商提供; 
stdin/stdout, printf/scanf由c标准库封装; 并且内部各自维护一个缓冲区buffer; buffer的本质是一段内存空间;

如何去刷新stdout缓冲区:
	* +'\n' 输出的字符串有回车换行, 会自动刷新缓冲区
	* 程序运行结束, 也会刷新缓冲区
	* fflush(stdout);	// 用来清空文件流缓冲区的函数, 参数可以是stdout/stdin/stderr
	* 缓冲区大小默认是8192个字节, 只要填满了也会自动刷新
	* 设置缓冲区的目的是减少读写次数; 提升io效率

* 睡眠:

	// unistd.h  Linux系统下的头文件, windows没有
	usleep(1000);	// 1000微妙
	// windows是sleep(1), 单位是秒

#### 操作文件

* stdio.h头文件

* 案例:

	#include <stdio.h>
	
	void main()
	{
		// 文件指针;
		FILE *fp;
		// 打开文件名为hellotest的文件, 操作权限是 w, 写
		fp = fopen("hellotest","w");
		// 往文件指针中写入字符串, 和数字
		fprintf(fp,"xingwenpeng\t%d\d",10);
		// 关闭文件指针
		fclose(fp);
	}

* FILE, 
	
是一个结构体

typedef struct _IO_FILE FILE;

struct _IO_FILE {
	char * _IO_read_ptr;

	// ....
}

在Linux下可以查看到源码
cd /usr/include/

vi li	// 列出li的文件和文件夹列表
vi lib

vi libio.h	// 可以看到FILE的别名定义
vi stdio.h  // 可以看到struct _IO_FILE 结构体

ps: /typedef -> 搜索typedef关键字

FILE里面我们需要关心的:

当前读写指针位置
buffer指针, 默认8192字节
文件索引指针, 磁盘文件的位置

// 参数一是文件路径; 参数二是打开模式
FILE *fopen(const char *path, const char *mode)
// 相对路径(相对于当前的路径)和绝对路径(磁盘路径)
// mode类型:
	* r, read; 以读的形式打开文件
	* w, write; 以写的形式打开文件; 如果文件不存在, 创建文件; 如果文件存在, 截断源文件(清空源文件), 读写指针在文件开头
	* a, append; 追加, 写打开; 如果文件不存在, 会创建文件; 如果文件存在, 继续在上面写;
	* r+; 可读可写;如果文件不存在, 也不创建
	* w+; 可读可写打开文件; 如果文件不存在, 则创建文件; 如果存在, 则截断;
	* a+; 可读可写, 追加打开文件; 如果文件不存在; 则创建;

	* rb; 操作的文件是二进制; 这是windows平台下特有的读写模式;
	* wb
	* ab

* 二进制文件, 文本文件;
* 文本文件, 文本是可见的; 二进制文件, 取出的是字节, 例如a, 直接读出的是97


#### 打开文件失败的原因:

* 权限不够;
* 路径错误; 打开失败的话, 返回值是NULL
* model属性超出对文件操作的自有属性
* 打开文件数超出了系统设置上限(Linux默认是1024个文件)
	* 打开文件要占内存; 无限打开文件会占用内存;
* 写打开文件时, 磁盘空间不足;
	
* fprintf/sprintf/printf
	* fprintf(FILE *stream, char *s, ...);
	* sprintf(char *s_arr, char *s, ...);

* 每个程序默认打开了in/out/err三个文件

* fclose(FILE *fp)
	* fp必须是一个有效的指针; 不能为NULL;
	* 同一个文件指针不能fclose多次; 只能一次;

* fgets(char *s, int size, FILE *fp);
	* 一次从文件读一行;file gets;
	* size表示s中最多能读取的字符个数;
	* 接收"\n";
	* 读取到文件末尾或文件出错时返回NULL

* fputs(const char *s, FILE *fp);
	* writes the string s to stream, without its terminating nullbyte ('\0');
	* 将字符串s写到文件流中, 并且不追加字符串结束符

* 实现一个自己的mycp命令;

* fgetc(src)

	char ch;
	while((ch = fgetc(src))!=EOF)
	{
		// EOF, err or fail, c标准定义的宏定义, 值为-1
		fputc(ch,dest);	// 存入单个字符
	}

* size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

	* 示例:
	
		#include <stdio.h>
		
		struct STU{
			int id;
			char name[20];
			char sex;
			// 占的内存空间是28, why?
		}

		void main()
		{
			FILE *fp;
			struct STU a = {10,"xiaoming",'m'};
			fp = fopen("hellotest","w");
			fwrite(&a,sizeof(a),1,fp);
			fclose(fp);
		}

	* fread()
	
		struct STU b;
		FILE *fp = fopen("hellotest","r");
		fread(&b,sizeof(b),1,fp);
		printf("%d\t%s\t%c\n",b.id,b.name,b.sex);
		fclose(fp);
	* 类似于java中的序列化;
	* 参数类型: 
		* void *ptr; 泛型, 表示任意数据类型的指针;
		* size表示每条记录的内存大小, 一般用sizeof(ptr)
		* nmemb, 写的条数;
		* File *fp, 要保存到的文件

* fflush(FILE *fp)
	* 刷新缓冲区; 每个文件都有自己的缓冲区; 
	* fflush(NULL); 清空所有的I/O缓冲区;

* 扩展:
* sleep(5);	#include <unistd.h>	// unix下的头文件, windows没有这个头文件


* feof(FILE *fp)
	判断文件是否到达末尾; 没有返回0, 到达末尾了则返回1
	只判断, 调用该函数, 文件的指针不会变化

* fseek(); 定位文件指针
	* 案例:
	
		#include <stdio.h>

		void main()
		{
			char *s = "helloworld";
			FILE *fp = fopen("hello","w+");
			fputs(s,fp);
			fseek(fp,0,SEEK_SET);	// SEEK_SET, 文件首指针; SEEK_END, 文件末尾指针 // SEEK_CUR, 当前指针地址
			// 0表示offset, 偏移量; 这句话的意思是, 将文件的读写指针移动到首指针, 偏移量为0的地方
		}

		fseek(fp, 100, SEEK_END);
			// 这种操作一般叫做拓展文件空间
		fputc('\0');	// 相当于是占位符号; 不加这句, 则拓展实际上并没有拓展;
		拓展是在下一次写操作的时候才会真正的拓展;

		fseek(fp, -1, SEEK_END);	// 从文件的末尾向前移动一位;

		fseek(fp, -1, SEEK_SET);	// 这种操作没有意义; 索引越界

* rewind(FILE *stream);
	* 把读写位置移动到文件开头, 可以理解为底层实现是调用了fseek(fp,0,SEEK_SET);

* long ftell(FILE *stream);
	* 返回当前读写位置;

#### 作业;

统计一篇英文文章里出现频率最高的前10个单词;