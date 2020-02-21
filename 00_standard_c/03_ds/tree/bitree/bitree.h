#ifndef __BITREE_H__
#define __BITREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct _bitreenode_ {
	int data;
	struct _bitreenode_ *lchild,
						*rchild;
}bitnode_t;

extern bitnode_t *_creat_bitnode_(int value);
extern bitnode_t *creat_bitree(int start, int end);
extern int preorder(bitnode_t *root);
extern int inorder(bitnode_t *root);
extern int postorder(bitnode_t *root);
extern int nuorder(bitnode_t *root);
extern int free_bitree(bitnode_t *root);

#endif
