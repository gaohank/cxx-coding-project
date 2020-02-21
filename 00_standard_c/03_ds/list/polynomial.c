#include <stdio.h>
#include <stdlib.h>

typedef struct _data_type_ {
	int coeff;
	int exp;
}DateType;

typedef struct _link_node_ {
	DateType data;
	struct _link_node_ *next;
}LinkNode;

LinkNode *creat_linknode(DateType *data);
LinkNode *creat_empty_linklist(void);
int get_data(LinkNode *head);
int insert_linklist(LinkNode *head, DateType *data);
int show_linklist(LinkNode *head);
LinkNode *combine_linklist(LinkNode *lista, LinkNode *listb);

int main()
{
	LinkNode *lista = NULL,
			 *listb = NULL,
			 *listc = NULL;

	lista = creat_empty_linklist();
	listb = creat_empty_linklist();
	listc = creat_empty_linklist();
	
	get_data(lista);
	get_data(listb);

	show_linklist(lista);
	show_linklist(listb);

	listc = combine_linklist(lista,listb);
	show_linklist(listc);

	return 0;
}

LinkNode *creat_linknode(DateType *data)
{
	LinkNode *node = NULL;

	node = (LinkNode *)malloc(sizeof(LinkNode));
	node->data = *data;
	node->next = NULL;
	
	return node;
}

LinkNode *creat_empty_linklist(void)
{
	DateType data = {0,0};
	return creat_linknode(&data);
}

int get_data(LinkNode *head)
{
	DateType data;

	while(1)
	{
		while( 2 != scanf("%d,%d",&data.coeff, &data.exp))
			getchar();
		if(0 == data.coeff)
			break;
		insert_linklist(head, &data);
	}

	return 0;
}

int insert_linklist(LinkNode *head, DateType *data)
{
	LinkNode *new = NULL;
	while(NULL != head->next && head->next->data.exp > data->exp)
		head = head->next;
	if(NULL == head->next || head->next->data.exp < data->exp)
	{
		new = creat_linknode(data);
		new->next = head->next;
		head->next = new;
	}
	else
		head->next->data.coeff += data->coeff;
	
	return 0;
}

int show_linklist(LinkNode *head)
{
	head = head->next;
	while(NULL != head)
	{
		printf(" %dX^%d +",head->data.coeff, head->data.exp);
		head = head->next;
	}
	puts("\b ");
	return 0;
}

LinkNode *combine_linklist(LinkNode *lista, LinkNode *listb)
{
	LinkNode *head = lista;
	LinkNode *tmp = NULL;

	while(NULL != lista->next && NULL != listb->next)
	{
		if(lista->next->data.exp > listb->next->data.exp);
		else if(lista->next->data.exp == listb->next->data.exp)
		{
			lista->next->data.coeff += listb->next->data.coeff;
			tmp = listb->next;
			listb->next = tmp->next;
			free(tmp);
		}
		else
		{
			tmp = listb->next;
			listb->next = tmp->next;

			tmp->next = lista->next;
			lista->next = tmp;
		}
		lista = lista->next;
	}
	if(listb->next)
		lista->next = listb->next;
	free(listb);

	return head;
}
