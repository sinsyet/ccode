#include <stdio.h>
#include "link.h"
#include <stdlib.h>

// 声明链表头;
lnode *head;
// lnode *tail;
size_t sz;

// 生成节点;
lnode create_node(int item)
{
	printf("before start--\n");
	lnode node =(lnode)malloc(sizeof(lnode));
// 	lnode node = malloc(sizeof*node);
	printf("after malloc%d,%d\n",node->item,item);
	printf("size:%lu，size2:%lu\n",sizeof(node->item),sizeof(item));
//	lnode node = malloc(sizeof*node);
//	node->item = 3;
	printf("before111");
	if(!*head)
	{
		printf("after---");
		// 如果head不为0;
		*head = node;
		node->p = 0;
	}
	else
	{
		printf("hshhshs");
		lnode tmp;
		for(tmp = *head;tmp;tmp = tmp->next)
		{
			if(tmp->next == NULL)
			{
				tmp->next = node;
				node->p = tmp->p + 1;
				return node;
			}
		}
	}
	sz++;
	return node;
}

// 通过位置查找节点
lnode get_node(pos p)
{
	lnode tmp;
	for(tmp = *head; tmp; tmp = tmp->next)
	{
		if(tmp->p == p)
		{
			return tmp;
		}
	}
	
	return NULL;
}

// 通过值查找节点
lnode search_node(int item)
{
	lnode tmp;
	for(tmp = *head; tmp; tmp = tmp->next)
	{
		if(tmp->item == item)
		{
			return tmp;
		}
	}
	return NULL;
}

// 删除节点
void delete_node(lnode node)
{
	if(*head == node)
	{
		*head = (*head)->next;
		sz--;
		return;
	}

	lnode ln;
	for(ln = *head;ln;ln=ln->next)
	{
		if(node == ln->next);
		{
			ln->next = node->next;
			sz--;
			return;
		}
	}
}

// 交换节点
void swap_node(lnode n1,lnode n2)
{

}

// 遍历链表
void travel_links(void (*vist)(lnode))
{
	lnode ln;
	for(ln = *head;ln;ln=ln->next)
	{
		if(vist)
		{
			vist(ln);
		}
	}
}

// 获取链表的节点个数
size_t size()
{
	return sz;
}
