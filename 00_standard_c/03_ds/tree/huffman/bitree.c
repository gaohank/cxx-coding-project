#include "bitree.h"
#include "linkqueue.h"

BitreeNode *creat_bitree_node(BitreeData *data)
{
	BitreeNode *node = NULL;
	
	node = (BitreeNode *)malloc(sizeof(BitreeNode));
	node->btdata = *data;
	node->lchild = NULL;
	node->rchild = NULL;

	return node;
}

int nuorder_bitree(BitreeNode *root)
{
	LinkQueue *lq = NULL;

	lq = creat_empty_linkqueue((unsigned int)100);
	root->btdata.code = 1;
	enqueue(lq,root);
//	puts("------------");
//	_debug_(lq);

	while(!is_empty(lq))
	{
//		puts("------------");
		root = dequeue(lq);

		if(NULL == root->lchild && NULL == root->rchild)
		{
			printf("(%c) <%d> [%d]\n",root->btdata.ch, root->btdata.weight, root->btdata.code);
			continue;
		}
		if(root->lchild)
		{
			root->lchild->btdata.code = root->btdata.code * 10;
			enqueue(lq, root->lchild);
		}
		if(root->rchild)
		{
			root->rchild->btdata.code = root->btdata.code * 10 + 1;
			enqueue(lq, root->rchild);
		}
	}

	return 0;
}
