#include <stdio.h>
#include <stdlib.h>

typedef struct _linknode_{
	int data;
	struct _linknode_ *next;
}linknode_t;

typedef struct _linklist_{
	int m_len;
	int c_len;
	linknode_t *head;
}linklist_t;

linknode_t *_creat_linknode_(int value);
linklist_t *init_linklist(int len);
int free_linklist(linklist_t *list);
int show_linklist(linklist_t *list);
int insert_linklist(linklist_t *list, int value);
linknode_t *_locate_linklist_(linklist_t *list, int obj);
int delete_linklist(linklist_t *list, int obj);
int modify_linklist(linklist_t *list, int obj, int value);
int search_linklist(linklist_t *list, int *buff, int obj);

int main()
{
	int value;
	int ret;
	linklist_t *list = NULL;

	list = init_linklist(10);
	
	for (value = 100; ; value ++ ) {
		if (0 > insert_linklist(list, value))
			break;
	}
	
	show_linklist(list);
	
	delete_linklist(list, 100);
	show_linklist(list);

	modify_linklist(list, 101, 205);
	show_linklist(list);
	
	ret = search_linklist(list, &value, 2050);
	printf("obj[%d]: %d\n", ret, value);

	free_linklist(list);

	return 0;
}

linknode_t *_creat_linknode_(int value)
{
	linknode_t *node;

	node = (linknode_t *)malloc(sizeof(linknode_t));
	node->data = value;
	node->next = NULL;

	return node;
}

linklist_t *init_linklist(int len)
{
	linklist_t *list = NULL;

	list = (linklist_t *)malloc(sizeof(linklist_t));
	list->c_len = 0;
	list->m_len = len;
	list->head = _creat_linknode_(0);

	return list;
}

int free_linklist(linklist_t *list)
{
	linknode_t *tmp = NULL,
			   *p = list->head;

	while (NULL != p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(list);

	return 0;
}

int insert_linklist(linklist_t *list, int value)
{
	linknode_t *new = NULL;

	if (list->c_len >= list->m_len)
		return -1;

	new = _creat_linknode_(value);
	new->next = list->head->next;
	list->head->next = new;

	list->c_len ++;

	return 0;
}

int show_linklist(linklist_t *list)
{
	linknode_t *p = list->head->next;

	while (NULL != p) {
		printf("%3d ", p->data);
		p = p->next;
	}
	putchar('\n');
	return 0;

}

linknode_t *_locate_linklist_(linklist_t *list, int obj)
{
	linknode_t *p = list->head;

	while(NULL != p->next) {
		if (obj == p->next->data)
			return p;
		p = p->next;
	}
	return NULL;
}

int delete_linklist(linklist_t *list, int obj)
{
	linknode_t *position = NULL,
			   *tmp = NULL;

	if (list->c_len <= 0)
		return -1;

	position = _locate_linklist_(list, obj);
	if (NULL == position)
		return -1;
	tmp = position->next;
	position->next = tmp->next;
	free(tmp);

	list->c_len --;

	return 0;
}

int modify_linklist(linklist_t *list, int obj, int value)
{
	linknode_t *position = NULL;

	if (NULL == (position = _locate_linklist_(list, obj)))
		return -1;

	position->next->data = value;

	return 0;
}

int search_linklist(linklist_t *list, int *buff, int obj)
{
	linknode_t *position = NULL;

	if (NULL == (position = _locate_linklist_(list, obj)))
		return -1;
	*buff = position->next->data;

	return 0;
}
