
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

typedef struct _linkqueue_{
	int c_len;
	int t_len;
	LinkNode *head,
			 *tail;
}LinkQueue;

extern LinkQueue *create_linkqueue(int maxlen);
extern int free_linkqueue(LinkQueue *queue);
extern int enqueue(LinkQueue *queue, lndata_t value);
extern int dequeue(LinkQueue *queue, lndata_t *dest);
extern void _debug_linkqueue_(LinkQueue *queue);
extern int isfull_linkqueue(LinkQueue *queue);
extern int isempty_linkqueue(LinkQueue *queue);

#endif
