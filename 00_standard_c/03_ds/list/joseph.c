#include <stdio.h>
#include <stdlib.h>

typedef struct _linknode_{
	int data;
	struct _linknode_ *next;
}LinkNode;

LinkNode *creat_looplinklist(int len);
int show_looplinklist(LinkNode *list);
LinkNode *process_joseph(LinkNode *list, int rule);

int main()
{
	int nu = 0,
		rule = 0;
	LinkNode *list = NULL;

	scanf("%d%d",&nu, &rule);
	printf("%d-%d\n", nu, rule);
	list = creat_looplinklist(nu);
	list = process_joseph(list, rule);
	show_looplinklist(list);
	free(list);
	return 0;
}

LinkNode *creat_looplinknode(int value)
{
	LinkNode *node = NULL;

	node = (LinkNode *)malloc(sizeof(LinkNode));
	node->data = value;
	node->next = node;

	return node;
}

LinkNode *creat_looplinklist(int len)
{
	int i;
	LinkNode *list = NULL,
			 *node = NULL;

	list = creat_looplinknode(1);

	for(i = len; i > 1; i --)
	{
		node = creat_looplinknode(i);
		node->next = list->next;
		list->next = node;
	}
	return list;
}

int show_looplinklist(LinkNode *list)
{
	LinkNode *p = list;

	do{
		printf("%2d ", p->data);
		p = p->next;
	}while(p != list);
	putchar(10);

	return 0;
}

LinkNode *process_joseph(LinkNode *list, int rule)
{
	int i = 0;
	LinkNode *tmp = NULL;
	
	while(list->next != list)
	{
		i ++;
		if(i == rule -1)
		{
			tmp = list->next;
			list->next = tmp->next;
			free(tmp);
			i = 0;
		}
		list = list->next;
	}
}
