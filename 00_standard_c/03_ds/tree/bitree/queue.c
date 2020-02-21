#include "queue.h"

linkqueue_t *init_linkqueue(int len)
{
	linkqueue_t *queue = NULL;

	queue = (linkqueue_t *)malloc(sizeof(linkqueue_t));
	queue->maxlen = len;
	queue->curlen = 0;
	queue->head = _creat_linknode_(0);
	queue->tail = queue->head;

	return queue;
}

int free_linkqueue(linkqueue_t *queue)
{
	linknode_t *p = queue->head,
			   *tmp = NULL;

	while (NULL != p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(queue);

	return 0;
}

int isfull_linkqueue(linkqueue_t *queue)
{
	return queue->curlen >= queue->maxlen;
}

int isempty_linkqueue(linkqueue_t *queue)
{
	return queue->curlen <= 0;
// 	return queue->head == queue->tail;
}

int enqueue(linkqueue_t *queue, lnkdata_t value)
{
	linknode_t *new = NULL;

	if (isfull_linkqueue(queue))
		return -1;

	new = _creat_linknode_(value);
	queue->tail->next = new;
	queue->tail = new;
	queue->curlen ++;

	return 0;
}

int dequeue(linkqueue_t *queue, lnkdata_t *buff)
{
	linknode_t *p = queue->head;

	if (isempty_linkqueue(queue))
		return -1;

	queue->head = p->next;	
	free(p);
	
	*buff = queue->head->data;
	queue->curlen --;

	return 0;
}

void _debug_linkqueue_(linkqueue_t *queue)
{
	linknode_t *p = queue->head->next;

	puts("debug:");
	printf("maxlen: %d\tcurlen: %d\n", queue->maxlen, queue->curlen);
	
	while (NULL != p) {
		printf("%3p ", p->data);
		p = p->next;
	}
	puts("\n-----------------------------------------");
}
