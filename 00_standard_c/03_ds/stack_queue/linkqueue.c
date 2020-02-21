#include <stdio.h>
#include <stdlib.h>

typedef struct _linknode_{
	int data;
	struct _linknode_ *next;
}linknode_t;

typedef struct _linkqueue_{
	int maxlen;
	int curlen;
	linknode_t *head,
			   *tail;
}linkqueue_t;

linknode_t *_creat_linknode_(int value);
linkqueue_t *init_linkqueue(int len);
int free_linkqueue(linkqueue_t *queue);
int isfull_linkqueue(linkqueue_t *queue);
int isempty_linkqueue(linkqueue_t *queue);
int enqueue(linkqueue_t *queue, int value);
int dequeue(linkqueue_t *queue, int *buff);
void _debug_linkqueue_(linkqueue_t *queue);

int main()
{
	linkqueue_t *queue = NULL;
	int value;

	queue = init_linkqueue(10);

	puts("enqueue:");
	for (value = 100; ; value ++) {
		if (0 > enqueue(queue, value))
			break;
	}

#if DEBUG
	_debug_linkqueue_(queue);
#endif

	puts("dequeue:");
	while (0 <= dequeue(queue, &value))
		printf("%3d ", value);
	putchar('\n');

#if DEBUG
	_debug_linkqueue_(queue);
#endif

	puts("enqueue:");
	for (value = 100; ; value ++) {
		if (0 > enqueue(queue, value))
			break;
	}

#if DEBUG
	_debug_linkqueue_(queue);
#endif

	free_linkqueue(queue);

	return 0;
}

linknode_t *_creat_linknode_(int value)
{
	linknode_t *node = NULL;

	node = (linknode_t *)malloc(sizeof(linknode_t));
	node->data = value;
	node->next = NULL;

	return node;
}

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

int enqueue(linkqueue_t *queue, int value)
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

int dequeue(linkqueue_t *queue, int *buff)
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
		printf("%3d ", p->data);
		p = p->next;
	}
	puts("\n-----------------------------------------");
}
