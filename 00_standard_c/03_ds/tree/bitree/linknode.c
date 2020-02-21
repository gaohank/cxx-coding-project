#include "linknode.h"

linknode_t *_creat_linknode_(lnkdata_t value)
{
	linknode_t *node = NULL;

	node = (linknode_t *)malloc(sizeof(linknode_t));
	node->data = value;
	node->next = NULL;

	return node;
}
