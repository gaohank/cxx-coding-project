#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 6
#define M (1<<30)

typedef struct _graph_{
	int (*adjmatrix)[N];
	int vn;
}Graph;

Graph *creat_adjmatrix_graph(int vertex_n);
int free_adjmatrix_graph(Graph *mg);


int main()
{
	int i, j, startvertex, count = 0, min, path;
	int s[N] = {0}, dist[N];
	Graph *mg = NULL;
	int user_data[N][N] = {
		{M,10,20,15,M,M},
		{10,M,8,M,25,M},
		{20,8,M,16,35,40},
		{15,M,16,M,M,5},
		{M,25,35,M,M,30},
		{M,M,40,5,30,M}
	};

	startvertex = 0;
	s[startvertex] = 1;
	mg = creat_adjmatrix_graph(N);
	memcpy(mg->adjmatrix,user_data, sizeof(user_data));
	for (i=0; i<N; i++)
		dist[i] = mg->adjmatrix[startvertex][i];

	for(count = 0; count < N; count ++)
	{
		path = M;
		for (i=0; i<N; i++)
		{
			if ( s[i] == 0  && dist[i] < path)
			{
				path = dist[i];
				min = i;
			}
		}
		s[min] = 1;
		for (i=0; i<N; i++)
		{
			int tmp = path + mg->adjmatrix[min][i];
			if (s[i] == 0 &&  dist[i] > tmp)
				dist[i] = tmp;
		}
	}

	for (i=0; i<N; i++)
	{
		printf("V%d -> V%d : %d\n", startvertex, i, dist[i]);
	}

	return 0;
}

Graph *creat_adjmatrix_graph(int vertex_n)
{
	Graph *mg = NULL;

	mg = (Graph *)malloc(sizeof(Graph));
	mg->adjmatrix = (int(*)[N])malloc(sizeof(int) * vertex_n * vertex_n);
	memset(mg->adjmatrix, 0, sizeof(int) * vertex_n * vertex_n);
	mg->vn = vertex_n;

	return mg;
}

int free_adjmatrix_graph(Graph *mg)
{
	free(mg->adjmatrix);
	free(mg);
	return 0;
}
