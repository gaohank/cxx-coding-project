#include <queue.h>
#include <stack.h>

#define STACK_M1_SIZE	4
#define STACK_M5_SIZE	11
#define STACK_H1_SIZE	11
#define QUEUE_LEN		27

int check_queue(linkqueue_t *queue);

int main()
{
	seqstack_t *m1 = NULL,
			   *m5 = NULL,
			   *h1 = NULL;
	linkqueue_t *queue = NULL;
	int ball = 1,
		tmp;
	int timer = 0;

	m1 = init_seqstack(STACK_M1_SIZE);
	m5 = init_seqstack(STACK_M5_SIZE);
	h1 = init_seqstack(STACK_H1_SIZE);
	queue = init_linkqueue(QUEUE_LEN);

	while (0 <= enqueue(queue, ball))
		ball ++;
	
	while (1) {
		dequeue(queue, &ball);

		if (0 == push_seqstack(m1, ball))
			continue;
		while (0 == pop_seqstack(m1, &tmp))
			enqueue(queue, tmp);

		if (0 == push_seqstack(m5, ball))
			continue;
		while (0 == pop_seqstack(m5, &tmp))
			enqueue(queue, tmp);

		if (0 == push_seqstack(h1, ball))
			continue;
		while (0 == pop_seqstack(h1, &tmp))
			enqueue(queue, tmp);
		
		enqueue(queue, ball);

		timer ++;
		if (check_queue(queue))
			break;
	}

	printf("%dd-%dh\n", timer / 2, timer % 2);
	
	free_linkqueue(queue);
	free_seqstack(m1);
	free_seqstack(m5);
	free_seqstack(h1);
	return 0;
}

int check_queue(linkqueue_t *queue)
{
	linknode_t *p = queue->head->next;

	while (NULL != p && NULL != p->next) {
		if (p->data > p->next->data)
			return 0;
		p = p->next;
	}
	return 1;
}
