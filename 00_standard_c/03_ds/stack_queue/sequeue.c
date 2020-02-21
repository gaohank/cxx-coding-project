#include <stdio.h>
#include <stdlib.h>

typedef struct _sequeue_{
	int head;
	int tail;
	int maxlen;
	int *buff;
}sequeue_t;

sequeue_t *init_sequeue(int len);
int free_sequeue(sequeue_t * queue);
int enqueue(sequeue_t *queue, int value);
int dequeue(sequeue_t *queue, int *buff);
void _debug_sequeue_(sequeue_t *queue);
int isfull_sequeue(sequeue_t *queue);
int isempty_sequeue(sequeue_t *queue);

int main()
{
	int value;
	int count;
	
	sequeue_t *queue;
	queue = init_sequeue(10);
	
	puts("enqueue:");
	for (value = 100; ; value ++) {
		if (0 > enqueue(queue, value))
			break;
	}
#if DEBUG
	_debug_sequeue_(queue);
#endif


	puts("dequeue:");
	for (count = 0; count < 5; count ++) {
		dequeue(queue, &value);
			printf("%3d ", value);
	}
	putchar('\n');

#if DEBUG
	_debug_sequeue_(queue);
#endif
	
	puts("enqueue:");
	for (value = 200; ; value ++) {
		if (0 > enqueue(queue, value))
			break;
	}
#if DEBUG
	_debug_sequeue_(queue);
#endif

	puts("dequeue:");
	while (0 == dequeue(queue, &value))
		printf("%3d ", value);
	putchar('\n');

#if DEBUG
	_debug_sequeue_(queue);
#endif

	
	free_sequeue(queue);

	return 0;
}

sequeue_t *init_sequeue(int len)
{
	sequeue_t *queue = NULL;

	queue = (sequeue_t *)malloc(sizeof(sequeue_t));
	queue->head = 0;
	queue->tail = 0;
	queue->maxlen = len;
	queue->buff = (int *)malloc(sizeof(int) * len);

	return queue;
}

int free_sequeue(sequeue_t * queue)
{
	free(queue->buff);
	free(queue);

	return 0;
}

int isfull_sequeue(sequeue_t *queue)
{
	return (queue->tail + 1) % queue->maxlen == queue->head;
}

int isempty_sequeue(sequeue_t *queue)
{
	return queue->tail == queue->head;
}

int enqueue(sequeue_t *queue, int value)
{

	if (isfull_sequeue(queue))
		return -1;

	queue->buff[queue->tail] =  value;
	queue->tail = (queue->tail + 1) % queue->maxlen;

	return 0;
}

int dequeue(sequeue_t *queue, int *buff)
{
	if (isempty_sequeue(queue))
		return -1;
	
	*buff = queue->buff[queue->head];
	queue->head = (queue->head + 1) % queue->maxlen;

	return 0;
}

void _debug_sequeue_(sequeue_t *queue)
{
	int index;
	
	puts("debug: ");
	printf("head: %d\ttail: %d\tmaxlen: %d\n", queue->head, queue->tail,
			queue->maxlen);
	for (index = 0; index < queue->maxlen; index ++)
		printf("%3d ", queue->buff[index]);
	puts("\n----------------------------------------------");
}
