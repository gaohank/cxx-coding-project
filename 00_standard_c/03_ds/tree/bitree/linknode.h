#ifndef __LINKNODE_H__
#define __LINKNODE_H__

#include "bitree.h"

typedef bitnode_t * lnkdata_t;

typedef struct _linknode_ {
	lnkdata_t data;
	struct _linknode_ *next;
}linknode_t;

#endif
