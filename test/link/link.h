#include <stdio.h>

#ifndef _LINK_H_
#define _LINK_H_

// 这段宏定义的含义是:
// 如果没有定义 _LINK_H_, 则定义，结束定义的位置
// if not def,define endif

typedef unsigned int pos;

// 给节点设置一个别名; 别名要设置在struct link_node前，因为结构体里面
// 也引用了这样的别名; 如果定义在后面，会导致编译器不认识lnode;
typedef struct link_node* lnode;
// 定义一个链表节点:
struct link_node
{
	pos p;
	int item;
	lnode next;
};

// 生成节点;
lnode create_node(int item);

// 通过位置查找节点
lnode get_node(pos p);

// 通过值查找节点
lnode search_node(int item);

// 删除节点
void delete_node(lnode node);

// 交换节点
void swap_node(lnode ln1,lnode ln2);

// 遍历链表
void travel_links(void (*vist)(lnode));

// 获取链表的节点个数
size_t size();
#endif
