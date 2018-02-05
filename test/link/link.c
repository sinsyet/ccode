#include <stdio.h>
#include "link.h"
#include <stdlib.h>

// 声明链表头;
// lnode *tail;
// size_t sz;

// 生成节点;
lnode create_node(lnode *nhead,int item)
{
//	lnode nd =(lnode)malloc(sizeof(*nd));
 	lnode nd = malloc(sizeof*nd);
	nd->item = item;

	// if(!(*nhead))	// 这里操作非法:
//	printf("%p\n",*nhead);	// 这里的值为nil, 不能做 !nil这样的运算
	if(*(nhead) == NULL)
	{
		*nhead = nd;
		nd->p = 0;
	}
	else
	{
		lnode tmp;
		for(tmp = *nhead;tmp;tmp = tmp->next)
		{
			if(tmp->next == NULL)
			{
				tmp->next = nd;
				nd->p = tmp->p + 1;
				break;
			}
		}
	}
	return nd;
}

// 通过位置查找节点
lnode get_node(lnode *nhead,pos p)
{
	lnode tmp;
	for(tmp = *nhead; tmp; tmp = tmp->next)
	{
		if(tmp->p == p)
		{
			return tmp;
		}
	}
	
	return NULL;
}

// 通过值查找节点
lnode search_node(lnode *nhead,int item)
{
	lnode tmp;
	for(tmp = *nhead; tmp; tmp = tmp->next)
	{
		if(tmp->item == item)
		{
			return tmp;
		}
	}
	return NULL;
}

// 删除节点
void delete_node(lnode *nhead, lnode node)
{
	if(*nhead == node)
	{
		*nhead = (*nhead)->next;
		return;
	}

	lnode ln;
	for(ln = *nhead;ln;ln=ln->next)
	{
		if(node == ln->next);
		{
			ln->next = node->next;
			return;
		}
	}
}

// 交换节点
/*
void swap_node(lnode n1,lnode n2)
{

}
*/

// 遍历链表
void travel_links(lnode *nhead,void (*vist)(lnode))
{
	lnode ln;
	for(ln = *nhead;ln;ln=ln->next)
	{
		if(vist)
		{
			vist(ln);
		}
	}
}

// 获取链表的节点个数
size_t size(lnode *nhead)
{
	lnode tmp;
	size_t sz = 0;
	for(tmp = *nhead;tmp != NULL; tmp = tmp->next)
	{
		if(tmp == NULL)
		{
			break;
		}
		else
		{
			sz++;
		}
	}
	return sz;
}
