#include <stdio.h>
#include "link.h"
// #include <stdlib.h>


void link_travel(lnode ln)
{
	printf("pos:%u,item:%d\n",ln->p,ln->item);
}

void main()
{

	lnode head = NULL;
	lnode nd = create_node(&head,3);

	printf("%d\n",nd->item);
	
	create_node(&head,10);
	create_node(&head,22);
	create_node(&head,19);
	create_node(&head,99);
	size_t sz = size(&head);
	printf("size: %lu\n",sz);
	travel_links(&head,link_travel);
	
	printf("------------------------------------\n");
	lnode nd4 = search_node(&head,4);
	if(nd4)
	{
		link_travel(nd4);
	}
	else
	{
		printf("nd4 is NULL\n");
	}
	printf("------------------------------------\n");
	lnode nd4_2 = get_node(&head,4);
	if(nd4_2)
	{
		link_travel(nd4_2);
	}
	else
	{
		printf("nd4_2 is NULL");
	}
}
