#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include "linknode.h"

typedef struct _linkstack_{
	int curlen;
	int maxlen;
	struct _linknode_*top;
}linkstack_t;

extern linknode_t *_creat_linknode_(lnkdata_t value);
extern linkstack_t *init_linkstack(int len);
extern int free_linkstack(linkstack_t *stack);
extern int push_linkstack(linkstack_t *stack, lnkdata_t value);
extern int pop_linkstack(linkstack_t *stack, lnkdata_t *buff);
extern void _debug_linkstack(linkstack_t *stack);
extern int isfull_linkstack(linkstack_t *stack);
extern int isempty_linkstack(linkstack_t *stack);
extern int gettop_linkstack(linkstack_t *stack, lnkdata_t *buff);

#endif
