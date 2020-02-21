#include <stdio.h>
#include <stdlib.h>

typedef struct _bitree_node_{
	int data;
	struct _bitree_node_ *lchild,
						 *rchild;
}BitNode;

BitNode *create_bitree(void);
int inorder(BitNode *root);
BitNode *create_bitnode(int value);
int insert_bitnode(BitNode **root, int value);
BitNode * search_bitnode(BitNode *root, int obj);

int main()
{
	BitNode *root = NULL;
	int value;
	BitNode *p;

	root = create_bitree();
	inorder(root);
	puts("\ninput witch number do you want to search:");
	scanf("%d",&value);
	p = search_bitnode(root, value);
	if(p == NULL)
		printf("%d not found !\n", value);
	else
		printf("%p->%d\n", p, p->data);
	return 0;
}

int insert_bitnode(BitNode **root, int value)
{
	BitNode *p = *root,
			*site = NULL;
	puts("-----------");
	
	while(NULL != p)
	{
		if(value == p->data)
			return 0;
		site = p;
		p = value > p->data ? p->rchild : p->lchild;
	}

	p = create_bitnode(value);
	if(NULL == *root)
		*root = p;
	else if(value < site->data)
		site->lchild = p;
	else
		site->rchild = p;

	return 0;
}


BitNode *create_bitree(void)
{
	int value;
	BitNode *root = NULL;

	while(1)
	{
		while( 1 != scanf("%d", &value))
			getchar();
		if(value == 0)
			break;
		
		insert_bitnode(&root, value);
	}
	return root;
}

int inorder(BitNode *root)
{
	if(root == NULL)
		return -1;
	inorder(root->lchild);
	printf("%3d ", root->data);
	inorder(root->rchild);

	return 0;
}

BitNode *create_bitnode(int value)
{
	BitNode *node = NULL;

	node = (BitNode *)malloc(sizeof(BitNode));
	node->data = value;
	node->lchild = NULL;
	node->rchild = NULL;

	return node;
}

BitNode * search_bitnode(BitNode *root, int obj)
{
	BitNode *p = root;

	while(p != NULL && p->data != obj)
	{
		if(obj < p->data)
			p = p->lchild;
		else
			p = p->rchild;
	}
	return p;
}
