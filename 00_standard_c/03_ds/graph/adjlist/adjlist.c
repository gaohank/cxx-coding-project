#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"
#include "queue.h"

typedef struct _adjlist_graph_{
	int vn;
	LinkNode *relation;
	char *visit;
}LinkGraph;

LinkGraph *create_linkgraph(int vn);
int free_linkgraph(LinkGraph *graph);
int add_edge(LinkGraph *graph, int vx, int vy);
int show_linkgraph(LinkGraph *graph);
int first_adjacency(LinkGraph *graph, int vertex);
int next_adjacency(LinkGraph *graph, int vx, int vy);
int DFS(LinkGraph *graph, int vertex);
int BFS(LinkGraph *graph, int vertex);

int main()
{
	LinkGraph *graph = NULL;

#if 0
	int vn, vy, vx;
	puts("input number of vertexes:");
	while( 1 != scanf("%d", &vn))
		getchar();
	graph = create_linkgraph(vn);
	
	while(1)
	{
		while(2 != scanf("%d,%d", &vx, &vy))
			getchar();
		if(vx == vy)
			break;
		add_edge(graph, vx, vy);
		add_edge(graph, vy, vx);
	}
#else
	int i, vn = 6;
	int userdata[][2] = {
		{0,5}, 
		{1,3}, 
		{1,5},
		{2,3}
	};
	
	graph = create_linkgraph(vn);

	for(i = 0; i < sizeof(userdata) / sizeof(*userdata); i ++)
	{
		add_edge(graph, userdata[i][0], userdata[i][1]);
		add_edge(graph, userdata[i][1], userdata[i][0]);
	}
#endif
	show_linkgraph(graph);
#if 0
	while(1)
	{
		puts("first adjacency:");
		while( 1 != scanf("%d", &vx))
			getchar();
		if(vx < 0)
			break;
		vn = first_adjacency(graph, vx);
		printf("v%d->v%d\n", vx, vn);
	}
	
	while(1)
	{
		puts("next adjacency:");
		while( 2 != scanf("%d,%d", &vx, &vy))
			getchar();
		if(vx == vy)
			break;
		vn = next_adjacency(graph, vx, vy);
		printf("(v%d,v%d)->v%d\n", vx, vy, vn);
		
	}
#endif
	
	puts("DFS:");
	i = 0;
	for(i = 0; i < graph->vn; i ++)
		DFS(graph, i);
	puts("\b ");
	memset(graph->visit, 0, graph->vn);

	puts("BFS:");
	for(i = 0; i < graph->vn; i ++)
		BFS(graph, i);
	puts("\b ");
	
	free_linkgraph(graph);
	return 0;
}

LinkGraph *create_linkgraph(int vn)
{
	LinkGraph *graph = NULL;

	graph = (LinkGraph *)malloc(sizeof(LinkGraph));
	graph->vn = vn;
	graph->relation = (LinkNode *)malloc(sizeof(LinkNode) * vn);
	memset(graph->relation, 0, sizeof(LinkNode) * vn);
	graph->visit = (char *)malloc(vn);
	memset(graph->visit, 0, vn);

	return graph;
}

int free_linkgraph(LinkGraph *graph)
{
	LinkNode *head = NULL;	
	int i;

	for(i = 0; i < graph->vn; i ++)
	{
		head = graph->relation[i].next;
		free_linklist(head);
	}
	free(graph->visit);
	free(graph->relation);
	free(graph);

	return 0;
}

int add_edge(LinkGraph *graph, int vx, int vy)
{
	LinkNode *head = NULL,
			 *new = NULL;
	
	if(vx < 0 || vx >= graph->vn || vy < 0 || vy >= graph->vn)
		return -1;

	head = graph->relation + vx;
	while(NULL != head->next && head->next->lndata < vy)
		head = head->next;

	if(head->next == NULL || head->next->lndata > vy)
	{
		new = create_linknode(vy);
		new->next = head->next;
		head->next = new;
	}
	else
		return 0;
	return 0;
}

int show_linkgraph(LinkGraph *graph)
{
	LinkNode *head = NULL;
	int i;

	for(i = 0; i < graph->vn; i ++)
	{
		printf("v%d: ", i);
		head = graph->relation[i].next;
		while(NULL != head)
		{
			printf(" v%d,", head->lndata);
			head = head->next;
		}
		puts("\b ");
	}
	return 0;
}

int first_adjacency(LinkGraph *graph, int vertex)
{
	LinkNode *head = NULL;
	
	if(vertex < 0 || vertex >= graph->vn)
		return -1;
	
	head = graph->relation + vertex;
	if(NULL != head->next)
		return head->next->lndata;
	else
		return -1;
}

int next_adjacency(LinkGraph *graph, int vx, int vy)
{
	LinkNode *head = NULL;
	
	if(vx < 0 || vx >= graph->vn || vy < 0 || vy >= graph->vn)
		return -1;
	
	head = graph->relation[vx].next;

	while(NULL != head && head->lndata != vy)
		head = head->next;
	if(head == NULL || head->next == NULL)
		return -1;
	else
		return head->next->lndata;
}

int DFS(LinkGraph *graph, int vertex)
{
	int v1;
	
	if(graph->visit[vertex])
		return 0;
	
	printf("v%d,", vertex);
	graph->visit[vertex] = 1;

	v1 = first_adjacency(graph, vertex);

	while(v1 >= 0)
	{
		if(! graph->visit[v1])
			DFS(graph, v1);
		v1 = next_adjacency(graph, vertex, v1);
	}
	return 0;
}

int BFS(LinkGraph *graph, int vertex)
{
	LinkQueue *queue = NULL;
	int v1;
	
	if(graph->visit[vertex])
		return 0;
	
	
	queue = create_linkqueue(1 << 20);
	
	printf("v%d,", vertex);
	graph->visit[vertex] = 1;
	enqueue(queue, vertex);

	while(! isempty_linkqueue(queue))
	{
		dequeue(queue, &vertex);
		v1 = first_adjacency(graph, vertex);
		while(v1 >= 0)
		{
			if(!graph->visit[v1])
			{
				printf("v%d,", v1);
				graph->visit[v1] = 1;
				enqueue(queue, v1);
			}
			v1 = next_adjacency(graph, vertex, v1);
		}
	}
	
	free_linkqueue(queue);
	return 0;
}
