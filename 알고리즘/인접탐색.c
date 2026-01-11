#include <stdio.h>
#include <stdlib.h>
#define MAX_Vertices 50
#define TRUE 1;
#define FALSE 0;
typedef struct graphnode
{
	int vertex;
	struct graphnode* link;
} graphnode;

typedef struct graphtype
{
	int n;
	graphnode* adj_list[MAX_Vertices];
} graphtype;

void init(graphtype* g)
{
	g->n = 0;
	for (int i = 0; i < MAX_Vertices; i++) g->adj_list[i] = NULL;
}

void insertvertex(graphtype* g, int v)
{
	if (((g->n) + 1) > MAX_Vertices)
	{
		printf("그래프 정점의 개수 초과");
		return;
	}
	g->n++;
	return;
}
void insert_edge(graphtype* g, int u, int v)
{
	if (u >= g->n || v >= g->n)
	{
		printf("그래프에 없는 정점입니다.");
		return;
	}
	graphnode* node;
	node = (graphnode*)malloc(sizeof(graphnode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

}

void print_adj_list(graphtype* g)
{
	graphnode* node;
	for (int i = 0; i < g->n; i++)
	{
		printf("정점 %d의 인접 리스트", i);
		node = g->adj_list[i];
		while (node != NULL)
		{
			printf(" -> %d", node->vertex);
			node = node->link;
		}
		printf("\n");
	}
}

int visited[MAX_Vertices];
int parent[MAX_Vertices];
void dfs_list(graphtype* g, int v)
{
	graphnode* w;
	visited[v] = TRUE;
	printf("정점 %d 방문\n", v);
	for (w = g->adj_list[v]; w; w = w->link)
	{
		parent[w->vertex] = v;
		if (!visited[w->vertex]) dfs_list(g, w->vertex);
	}
}
int main(void)
{
	graphtype* g;
	g = (graphtype*)malloc(sizeof(graphtype));
	init(g);
	for (int i = 0; i < MAX_Vertices; i++) insertvertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 1, 3);
	insert_edge(g, 3, 1);
	insert_edge(g, 3, 2);
	insert_edge(g, 2, 3);
	print_adj_list(g);
	dfs_list(g, 0);
	//free(g);
	return 0;
}