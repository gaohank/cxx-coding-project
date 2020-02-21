#include "queue.h"

#if DEBUG
void _debug_linkqueue_(LinkQueue *queue)
{
	LinkNode *p = queue->head->next;

	while(NULL != p)
	{
		printf("%3d ", p->lndata);
		p = p->next;
	}
	putchar(10);

}
#endif

LinkQueue *create_linkqueue(int maxlen)
{
	LinkQueue *queue = NULL;

	queue = (LinkQueue *)malloc(sizeof(LinkQueue));
	queue->head = (LinkNode *)create_linknode(0);
	queue->tail = queue->head;
	queue->c_len = 0;
	queue->t_len = maxlen;

	return queue;
}

int free_linkqueue(LinkQueue *queue)
{
	LinkNode *p = queue->head,
			 *tmp = NULL;

	while(NULL != p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(queue);

	return 0;
}

int isfull_linkqueue(LinkQueue *queue)
{
	return queue->c_len >= queue->t_len;
}

int isempty_linkqueue(LinkQueue *queue)
{
	return queue->c_len <= 0;
}

int enqueue(LinkQueue *queue, lndata_t value)
{
	LinkNode *new = NULL;

	if(isfull_linkqueue(queue))
		return -1;

	new = create_linknode(value);
	queue->tail->next = new;
	queue->tail = new;
	queue->c_len ++;

	return 0;
}

int dequeue(LinkQueue *queue, lndata_t *dest)
{
	LinkNode *tmp = queue->head;

	if(isempty_linkqueue(queue))
		return -1;

	queue->head = tmp->next;
	free(tmp);
	*dest = queue->head->lndata;
	queue->c_len --;

	return 0;
}
