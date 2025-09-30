#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5

typedef struct Graphtype
{
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];

};
void intt(Graphtype* g)
{
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		for	(int j = 0; j < MAX_VERTICES; j++)
		{
			g->adj_mat[i][j] = 0;
		}
	}
	g->n = 0;
}

void insert_adj_mat(Graphtype* g, int v)
{
	if (g->n + 1 > MAX_VERTICES)
	{
		printf("정점의 수 추가\n");
		return;
	}
	g->n++;
}
void insert_adj(Graphtype* g, int start, int end)
{
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
void print_adj_mat(Graphtype* g)
{
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			printf("[%d] ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}
void count_adj_mat(Graphtype *g)
{
	for (int i = 0; i < g->n; i++)
	{
		int temp = 0;
		for (int j = 0; j < g->n; j++)
		{
			temp += g->adj_mat[i][j];
		}
		printf("%d행 차수 : %d\n", i, temp);
	}
}
int main(void)
{
	Graphtype* g;
	g = (Graphtype*)malloc(sizeof(Graphtype));
	intt(g);
	for (int i = 0; i < 4; i++)
	{
		insert_adj_mat(g, i);
	}
	insert_adj(g, 0, 1);
	insert_adj(g, 0, 2);
	insert_adj(g, 0, 3);
	insert_adj(g, 1, 2);
	insert_adj(g, 2, 3);
	print_adj_mat(g);
	count_adj_mat(g);
}