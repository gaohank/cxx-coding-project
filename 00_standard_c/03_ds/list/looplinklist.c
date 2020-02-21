#include <stdio.h>
#include <stdlib.h>

#define N	10

typedef struct _link_node_{
	int data;
	struct _link_node_ *next;
}LinkNode;

typedef struct _link_list_{
	int c_len;
	int t_len;
	LinkNode *head;
}LinkList;

LinkList *creat_linklist(int len);
int free_linklist(LinkList *list);
int insert_linknode(LinkList *list, int value);
int show_linklist(LinkList *list);
int delete_linknode(LinkList *list, int obj);
LinkNode *search_linknode(LinkList *list, int obj);
int modify_linknode(LinkList *list, int obj, int value);

int main()
{
	LinkList *list = NULL;
	LinkNode *node = NULL;
	int i = 1;

	list = creat_linklist(N);
	puts("insert:");
	while( 0 ==  insert_linknode(list, i * 100))
		i ++;
	puts("show:");
	show_linklist(list);
	puts("search:");
	node = search_linknode(list, 500);
	printf("%p->%d\n", node->next, node->next->data);
	puts("modify:");
	modify_linknode(list, 700, 1100);
	puts("show:");
	show_linklist(list);
	puts("delete all:");
	for(i = -10; i < 20; i ++)
		delete_linknode(list, i * 100);
	puts("show:");
	show_linklist(list);
	free_linklist(list);
#if 0
#endif
	return 0;
}

LinkNode *creat_linknode(int value)
{
	LinkNode *node = NULL;

	node = (LinkNode *)malloc(sizeof(LinkNode));
	node->data = value;
	node->next = node;

	return node;
}

LinkList *creat_linklist(int len)
{
	LinkList *list = NULL;

	list = (LinkList *)malloc(sizeof(LinkList));
	list->c_len = 0;
	list->t_len = len;
	list->head = creat_linknode(0);

	return list;
}


int insert_linknode(LinkList *list, int value)
{
	LinkNode *p = list->head,
			 *node = NULL;

	if(list->c_len >= list->t_len)
		return -1;

	while(list->head != p->next)
		p = p->next;
	node = creat_linknode(value);
	node->next = p->next;
	p->next = node;
	list->c_len ++;

	return 0;
}

int show_linklist(LinkList *list)
{
	LinkNode *p = list->head->next;

	while(list->head != p)
	{
		printf("%3d ", p->data);
		p = p->next;
	}
	putchar('\n');

	return 0;
}

int delete_linknode(LinkList *list, int obj)
{
	LinkNode *p = list->head,
			 *tmp = NULL;
	if(NULL == list || list->c_len <= 0)
		return -1;

#if 0
	while(NULL != p->next && p->next->data != obj)
		p = p->next;

	if(NULL == p->next)
		return -1;
#else
	if( NULL == (p = search_linknode(list, obj)))
		return -1;
#endif
	tmp = p->next;
	p->next = tmp->next;
	free(tmp);
	list->c_len --;

	return 0;
}

LinkNode *search_linknode(LinkList *list, int obj)
{
	LinkNode *p = list->head;
	
	while( list->head != p->next && p->next->data != obj)
		p = p->next;
#if 0
	if(NULL == p->next)
		return NULL;
	return p;
#else
	return list->head == p->next ? NULL : p;
#endif
}

int modify_linknode(LinkList *list, int obj, int value)
{
	LinkNode *p = NULL;

	p = search_linknode(list, obj);
	if(NULL == p)
		return -1;
	p->next->data = value;

	return 0;
}

int free_linklist(LinkList *list)
{
	LinkNode *p = list->head,
			 *tmp = NULL;

	while(list->head != p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(list);
	return 0;
}
