#include "linklist.h"

LinkNode *create_linknode(lndata_t value)
{
	LinkNode *node = NULL;

	node = (LinkNode *)malloc(sizeof(LinkNode));
	node->lndata = value;
	node->next = NULL;

	return node;
}

int free_linklist(LinkNode *head)
{
	LinkNode *tmp = head;

	while(head != NULL)
	{
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
	return 0;
}
