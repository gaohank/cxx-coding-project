#include <stdio.h>
#include <stdlib.h>

typedef struct _linknode_ {
	int data;
	struct _linknode_ *next;
}linknode_t;

typedef struct _linkstack_{
	int curlen;
	int maxlen;
	struct _linknode_*top;
}linkstack_t;

linknode_t *_creat_linknode_(int value);
linkstack_t *init_linkstack(int len);
int free_linkstack(linkstack_t *stack);
int push_linkstack(linkstack_t *stack, int value);
int pop_linkstack(linkstack_t *stack, int *buff);
void _debug_linkstack(linkstack_t *stack);
int isfull_linkstack(linkstack_t *stack);
int isempty_linkstack(linkstack_t *stack);
int gettop_linkstack(linkstack_t *stack, int *buff);

int main()
{
	linkstack_t *stack = NULL;
	int value;
	int ret;

	stack = init_linkstack(10);

	puts("push:");
	for (value = 100; ; value ++) {
		if (0 > push_linkstack(stack, value))
			break;
	}
	
	ret = gettop_linkstack(stack, &value);
	printf("top[%d]: %d\n", ret, value);

#if DEBUG
	_debug_linkstack(stack);
#endif
	puts("pop:");
	while (0 <= pop_linkstack(stack, &value))
		printf("%3d ", value);
	putchar('\n');
#if DEBUG
	_debug_linkstack(stack);
#endif
	
	ret = gettop_linkstack(stack, &value);
	printf("top[%d]: %d\n", ret, value);

	free_linkstack(stack);

	return 0;
}

linknode_t *_creat_linknode_(int value)
{
	linknode_t *node = NULL;

	node = (linknode_t *)malloc(sizeof(linknode_t));
	node->data = value;
	node->next = NULL;

	return node;
}

linkstack_t *init_linkstack(int len)
{
	linkstack_t *stack = NULL;

	stack = (linkstack_t *)malloc(sizeof(linkstack_t));
	stack->maxlen = len;
	stack->curlen = 0;
	stack->top = _creat_linknode_(0);

	return stack;
}

int free_linkstack(linkstack_t *stack)
{
	linknode_t *p = stack->top,
			   *tmp = NULL;

	while (NULL != p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(stack);

	return 0;
}

int isfull_linkstack(linkstack_t *stack)
{
	return stack->curlen >= stack->maxlen;
}

int isempty_linkstack(linkstack_t *stack)
{
	return stack->curlen <= 0;
//  return NULL == stack->top->next ? 1 : 0;
}

int push_linkstack(linkstack_t *stack, int value)
{
	linknode_t *new = NULL;

	if (isfull_linkstack(stack))
		return -1;

	new = _creat_linknode_(value);
	new->next = stack->top->next;
	stack->top->next = new;
	stack->curlen ++;

	return 0;
}

void _debug_linkstack(linkstack_t *stack)
{
	linknode_t *p = stack->top->next;

	puts("debug:");
	while (NULL != p) {
		printf("%3d ", p->data);
		p = p->next;
	}
	puts("\n------------------------------------");
}

int pop_linkstack(linkstack_t *stack, int *buff)
{
	linknode_t *p = stack->top->next;

	if (isempty_linkstack(stack))
		return -1;

	*buff = p->data;
	stack->top->next = p->next;
	free(p);
	stack->curlen --;

	return 0;
}

int gettop_linkstack(linkstack_t *stack, int *buff)
{
	if (isempty_linkstack(stack))
		return -1;
	*buff = stack->top->next->data;
	return 0;
}
