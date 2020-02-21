
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef int lndata_t;

typedef struct _linknode_{
	lndata_t lndata;
	struct _linknode_ *next;
}LinkNode;


extern LinkNode *create_linknode(lndata_t value);
extern int free_linklist(LinkNode *head);

#endif
