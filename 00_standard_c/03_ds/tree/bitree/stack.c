#include "stack.h"

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

int push_linkstack(linkstack_t *stack, lnkdata_t value)
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
		printf("%p ", p->data);
		p = p->next;
	}
	puts("\n------------------------------------");
}

int pop_linkstack(linkstack_t *stack, lnkdata_t *buff)
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

int gettop_linkstack(linkstack_t *stack, lnkdata_t *buff)
{
	if (isempty_linkstack(stack))
		return -1;
	*buff = stack->top->next->data;
	return 0;
}
