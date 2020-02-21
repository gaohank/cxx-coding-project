#include "bitree.h"
#include "stack.h"
#include "queue.h"

int main()
{
	bitnode_t *root = NULL;

	root = creat_bitree(1, 10);

	puts("preorder:");
	preorder(root);
	putchar(10);

	puts("inorder:");
	inorder(root);
	putchar(10);

	puts("postorder:");
	postorder(root);
	putchar(10);

	puts("nuorder:");
	nuorder(root);
	putchar(10);

	free_bitree(root);

	return 0;
}

bitnode_t *_creat_bitnode_(int value)
{
	bitnode_t *node = NULL;

	node = (bitnode_t *)malloc(sizeof(bitnode_t));
	node->data = value;
	node->lchild = NULL;
	node->rchild = NULL;

	return node;
}

bitnode_t *creat_bitree(int start, int end)
{
	bitnode_t *root = NULL;

	root = _creat_bitnode_(start);
	if (start * 2 <= end)
		root->lchild = creat_bitree(start * 2, end);
	if (start * 2 + 1 <= end)
		root->rchild = creat_bitree(start * 2 + 1, end);

	return root;
}

#if 0
int preorder(bitnode_t *root)
{
	if (NULL == root)
		return -1;
	printf("%3d ", root->data);
	preorder(root->lchild);
	preorder(root->rchild);

	return 0;
}
#else

int preorder(bitnode_t *root)
{
	linkstack_t *stack = NULL;
	
	stack = init_linkstack(100);
	push_linkstack(stack, root);

	while (!isempty_linkstack(stack)) {
		if (NULL != root) {
			printf("%3d ", root->data);
			push_linkstack(stack, root);
			root = root->lchild;
		}else {
			pop_linkstack(stack, &root);
			root = root->rchild;
		}
	}

	free_linkstack(stack);
	return 0;	
}
	
#endif

int inorder(bitnode_t *root)
{
	if (NULL == root)
		return -1;
	inorder(root->lchild);
	printf("%3d ", root->data);
	inorder(root->rchild);

	return 0;
}

int postorder(bitnode_t *root)
{
	if (NULL == root)
		return -1;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%3d ", root->data);

	return 0;
}

int free_bitree(bitnode_t *root)
{
	if (root == NULL)
		return -1;
	
	free_bitree(root->lchild);
	free_bitree(root->rchild);
	free(root);

	return 0;
}

int nuorder(bitnode_t *root)
{
	linkqueue_t *queue = NULL;

	queue = init_linkqueue(100);
	enqueue(queue, root);

	while (! isempty_linkqueue(queue)) {
		
		dequeue(queue, &root);
		printf("%3d ", root->data);

		if (NULL != root->lchild)
			enqueue(queue, root->lchild);
		if (NULL != root->rchild)
			enqueue(queue, root->rchild);
	}

	free_linkqueue(queue);

	return 0;
}
