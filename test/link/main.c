#include <stdio.h>
#include "link.h"
// #include <stdlib.h>


void link_travel(lnode ln)
{
	printf("pos:%u,item:%d\n",ln->p,ln->item);
}

void main()
{

//	lnode node = malloc(sizeof(lnode));
//	node->item = 3;
//	printf("%d\n",node->item);
	create_node(3);

/*
before start--
after malloc0,3
size:4，size2:4
段错误 (核心已转储)

*/
	
//	create_node(8);
//	create_node(5);
//	create_node(9);
//	create_node(6);
//	printf("size: %lu\n",size());
//	travel_links(link_travel);
}
