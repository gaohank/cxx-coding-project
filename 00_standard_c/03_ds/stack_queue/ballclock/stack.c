#include <stack.h>

seqstack_t *init_seqstack(int len)
{
	seqstack_t *stack = NULL;

	stack = (seqstack_t*)malloc(sizeof(seqstack_t));
	stack->buff = (int *)malloc(sizeof(int) * len);
	stack->top = 0;
	stack->len = len;

	return stack;
}

int free_seqstack(seqstack_t *stack)
{
	free(stack->buff);
	free(stack);

	return 0;
}

int isfull_seqstack(seqstack_t *stack)
{
	return stack->top >= stack->len;
}

int isempty_seqstack(seqstack_t *stack)
{
	return stack->top <= 0;
}

int push_seqstack(seqstack_t *stack, int value)
{
	if (isfull_seqstack(stack))
		return -1;
	
	stack->buff[stack->top ++] = value;

	return 0;
}

void _debug_seqstack_(seqstack_t *stack)
{
	int index;

	puts("debug:");
	for (index = 0; index < stack->top; index ++)
		printf("%3d ", stack->buff[index]);
	putchar('\n');
}

int pop_seqstack(seqstack_t *stack, int *buff)
{
	if (isempty_seqstack(stack))
		return -1;
	*buff = stack->buff[-- stack->top];
	return 0;
}

int gettop_seqstack(seqstack_t *stack, int *buff)
{
	if (isempty_seqstack(stack))
		return -1;

	*buff = stack->buff[stack->top - 1];

	return 0;
}
