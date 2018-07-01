#### static

main.c

	// 智能在当前c文件中使用
	static void test(){}

	extern int age();	// 等效于 int age();

	extern int age;	// 有一个变量, 类型是int,已经在其他c文件中定义了, 这里直接引用

	int age;	// 定义全局变量

#### 申请内存

* 申请的内存是在堆中, 栈内存有线, 不能申请超大内存

* void *malloc(size_t len);  // 通常是 sizeof(t) * i
* void *calloc(size_t unit_len, size_t count);// 每块内存的大小, 申请多少块
* void *realloc(void *p, size_t _new_size); 重新分配内存, _new_size包括了扩充前的len

* 如果内存不够, 返回的地址值是NULL, 但是这种错误通常是致命的, 

		if(p1 == NULL)
		{
			exit(0);
		}
* realloc

	- 参数一位NULL, 参数2大于0, 则使用相当于就是malloc, 分配新内存
	- 参数一不为NULL, 参数二为0, 则释放参数一指向的指针, 返回NULL, 相当于free
	- 参数一不为NULL, 参数二大于0, 若参数二大于原_len, 则增加内存块, 小于原_len, 缩小内存块, 减少的部分系统会帮助释放; realloc

---

#### 结构体

结构体的对齐模式

按照最大值对齐