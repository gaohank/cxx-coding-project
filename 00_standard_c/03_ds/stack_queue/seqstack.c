#include <stdio.h>
#include <stdlib.h>

typedef struct _seqstack_{
	int len;
	int top;
	int *buff;
}seqstack_t;

seqstack_t *init_seqstack(int len);
int free_seqstack(seqstack_t *stack);
int push_seqstack(seqstack_t *stack, int value);
int pop_seqstack(seqstack_t *stack, int *buff);
int gettop_seqstack(seqstack_t *stack, int *buff);
void _debug_seqstack_(seqstack_t *stack);

int main()
{
	int value;
	int ret;
	seqstack_t *stack = NULL;

	stack = init_seqstack(10);

	puts("push");
	for (value = 100; ; value ++) {
		if (0 > push_seqstack(stack, value))
			break;
	}
#if DEBUG	
	_debug_seqstack_(stack);
#endif
	
	ret = gettop_seqstack(stack, &value);
	printf("top[%d]: %d\n", ret, value);
	
	puts("pop:");
	while (0 == pop_seqstack(stack, &value))
		printf("%3d ", value);
	putchar('\n');

#if DEBUG	
	_debug_seqstack_(stack);
#endif

	ret = gettop_seqstack(stack, &value);
	printf("top[%d]: %d\n", ret, value);

	free_seqstack(stack);
	return 0;
}


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
