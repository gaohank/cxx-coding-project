#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct _seqstack_{
	int len;
	int top;
	int *buff;
}seqstack_t;

extern seqstack_t *init_seqstack(int len);
extern int free_seqstack(seqstack_t *stack);
extern int push_seqstack(seqstack_t *stack, int value);
extern int pop_seqstack(seqstack_t *stack, int *buff);
extern int gettop_seqstack(seqstack_t *stack, int *buff);
extern void _debug_seqstack_(seqstack_t *stack);

#endif
