#include <stdio.h>
#include <stdlib.h>

typedef struct _dlinknode_{
	int data;
	struct _dlinknode_ *next,
					   *pre;
}dlinknode_t;

typedef struct _dlinklist_{
	int m_len;
	int c_len;
	dlinknode_t *head;
}dlinklist_t;

dlinknode_t *_creat_dlinknode_(int value);
dlinklist_t *init_dlinklist(int len);
int free_dlinklist(dlinklist_t *list);
int show_dlinklist(dlinklist_t *list);
int insert_dlinklist(dlinklist_t *list, int value);
dlinknode_t *_locate_dlinklist_(dlinklist_t *list, int obj);
int delete_dlinklist(dlinklist_t *list, int obj);
int modify_dlinklist(dlinklist_t *list, int obj, int value);
int search_dlinklist(dlinklist_t *list, int *buff, int obj);

int main()
{
	int value;
	int ret;
	dlinklist_t *list = NULL;

	list = init_dlinklist(10);

	for (value = 100; ; value ++) {
		if (0 > insert_dlinklist(list, value))
			break;
	}
	show_dlinklist(list);
	
	delete_dlinklist(list, 100);
	show_dlinklist(list);

	modify_dlinklist(list, 105, 205);
	show_dlinklist(list);

	ret = search_dlinklist(list, &value, 205);
	printf("obj[%d]: %d\n", ret, value);
	
	free_dlinklist(list);
	return 0;
}

dlinknode_t *_creat_dlinknode_(int value)
{
	dlinknode_t *node = NULL;

	node = (dlinknode_t *)malloc(sizeof(dlinknode_t));
	node->data = value;
	node->pre = NULL;
	node->next = NULL;

	return node;
}

dlinklist_t *init_dlinklist(int len)
{
	dlinklist_t *list = NULL;

	list = (dlinklist_t *)malloc(sizeof(dlinklist_t));
	list->c_len = 0;
	list->m_len = len;
	list->head = _creat_dlinknode_(0);

	return list;
}

int free_dlinklist(dlinklist_t *list)
{
	dlinknode_t *tmp = NULL,
			   *p = list->head;

	while (NULL != p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(list);

	return 0;
}


int show_dlinklist(dlinklist_t *list)
{
	dlinknode_t *p = list->head->next;
	dlinknode_t *tail = NULL;

	while (NULL != p) {
		printf("%3d ", p->data);
		tail = p;
		p = p->next;
	}
	putchar('\n');

	while (NULL != tail->pre) {
		printf("%3d ", tail->data);
		tail = tail->pre;
	}
	putchar('\n');
	return 0;

}

int insert_dlinklist(dlinklist_t *list, int value)
{
	dlinknode_t *new = NULL;

	if (list->c_len >= list->m_len)
		return -1;

	new = _creat_dlinknode_(value);
	new->next = list->head->next;
	if (NULL != new->next)
		new->next->pre = new;
	list->head->next = new;
	new->pre = list->head;
	list->c_len ++;
	return 0;
}

dlinknode_t *_locate_dlinklist_(dlinklist_t *list, int obj)
{
	dlinknode_t *p = list->head->next;

	while(NULL != p) {
		if (obj == p->data)
			return p;
		p = p->next;
	}
	return NULL;
}

int delete_dlinklist(dlinklist_t *list, int obj)
{
	dlinknode_t *position = NULL;

	if (list->c_len <= 0)
		return -1;

	if (NULL == (position = _locate_dlinklist_(list, obj)))
		return -1;
	position->pre->next = position->next;
	if (NULL != position->next)
		position->next->pre = position->pre;
	free(position);
	list->c_len --;

	return 0;
}

int modify_dlinklist(dlinklist_t *list, int obj, int value)
{
	dlinknode_t *position = NULL;

	if (NULL == (position = _locate_dlinklist_(list, obj)))
		return -1;

	position->data = value;

	return 0;
}

int search_dlinklist(dlinklist_t *list, int *buff, int obj)
{
	dlinknode_t *position = NULL;

	if (NULL == (position = _locate_dlinklist_(list, obj)))
		return -1;
	*buff = position->data;

	return 0;
}

