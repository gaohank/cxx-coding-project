#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N	5

typedef struct _graph_ {
	void *adjmatrix;
	int *visit;
	int vn;
}Graph;


Graph *creat_adjmatrix_graph(int vertex_n);
int add_edge(Graph *mg, int v1, int v2);
int show_adjmatrix_graph(Graph *mg);
int DFS(Graph *mg, int vertex);
int first_adjacency(Graph *mg, int vertex);
int next_adjacency(Graph *mg, int vertext, int adj);
int get_data(Graph *mg);

int main()
{
	Graph *mg = NULL;
	int vn = 0;
	

	puts("input the number of vertex:");
	while( 1 != scanf("%d",&vn))
		getchar();
	mg = creat_adjmatrix_graph(vn);
	puts("input your adjacent vertex:");
	get_data(mg);	
	puts("adjacent relation:");
	show_adjmatrix_graph(mg);
	puts("depth first search:");
//	for(vn = 0; vn < mg->vn; vn ++)
		DFS(mg, 0);
	puts("\b ");
	return 0;
}

Graph *creat_adjmatrix_graph(int vertex_n)
{
	Graph *mg = NULL;

	mg = (Graph *)malloc(sizeof(Graph));
	mg->adjmatrix = malloc(sizeof(int) * vertex_n * vertex_n);
	mg->visit = (int *)malloc(sizeof(int) * vertex_n);
	memset(mg->visit, 0, sizeof(int) * vertex_n);
	memset(mg->adjmatrix, 0, sizeof(int) * vertex_n * vertex_n);
	mg->vn = vertex_n;

	return mg;
}

int add_edge(Graph *mg, int v1, int v2)
{
	if(v1 < 0 || v1 >= mg->vn || v2 < 0 || v2 >= mg->vn)
		return -1;
	( (int(*)[mg->vn])mg->adjmatrix )[v1][v2] = 1;
	( (int(*)[mg->vn])mg->adjmatrix )[v2][v1] = 1;
	return 0;
}

int show_adjmatrix_graph(Graph *mg)
{
	int i,j;

	for(i = 0; i < mg->vn; i ++)
	{
		printf("v%d:",i);
		for(j = 0; j < mg->vn; j ++)
		{
			if(((int(*)[mg->vn])mg->adjmatrix)[i][j])
				printf(" v%d,",j);
		}
		puts("\b ");
	}
	return 0;
}

int DFS(Graph *mg, int vertex)
{
	int adj;

	if(mg->visit[vertex])
		return 0;
	printf(" v%d,",vertex);
	mg->visit[vertex] = 1;
	adj = first_adjacency(mg, vertex);

	while(adj >= 0)
	{
		DFS(mg, adj);
		adj = next_adjacency(mg, vertex, adj);
	}
	return 0;
}

int first_adjacency(Graph *mg, int vertex)
{
	int i;

	for(i = 0; i < mg->vn; i ++)
	{
		if(((int(*)[mg->vn])mg->adjmatrix)[vertex][i])
			return i;
	}
	return -1;
}

int next_adjacency(Graph *mg, int vertex, int adj)
{
	int i;

	for(i = adj + 1; i < mg->vn; i ++)
	{
		if(((int(*)[mg->vn])mg->adjmatrix)[vertex][i])
			return i;
	}
	return -1;

}

int get_data(Graph *mg)
{
	int v1, v2;

	while(1)
	{
		while( 2 != scanf("%d,%d",&v1, &v2))
			getchar();
		if(v1 == v2)
			break;
		add_edge(mg, v1, v2);
	}
	return 0;
}
