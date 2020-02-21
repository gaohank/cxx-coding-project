#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "linknode.h"

typedef struct _linkqueue_{
	int maxlen;
	int curlen;
	linknode_t *head,
			   *tail;
}linkqueue_t;

extern linknode_t *_creat_linknode_(lnkdata_t value);
extern linkqueue_t *init_linkqueue(int len);
extern int free_linkqueue(linkqueue_t *queue);
extern int isfull_linkqueue(linkqueue_t *queue);
extern int isempty_linkqueue(linkqueue_t *queue);
extern int enqueue(linkqueue_t *queue, lnkdata_t value);
extern int dequeue(linkqueue_t *queue, lnkdata_t *buff);
extern void _debug_linkqueue_(linkqueue_t *queue);

#endif
