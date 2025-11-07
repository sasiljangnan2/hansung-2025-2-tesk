#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct Prim_graph {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}Prim_graph;	

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int get_min_vertex(int n) // 최소 dist[v] 값을 갖는 정점 변환
{
	int v, i;

		for (i = 0; i < n; i++)
		{
			if (!selected[i])
			{
				v = i;
				break;
			}
		}
		for (i = 0; i < n; i++) if (!selected[i] && distance[i] < distance[v]) v = i; // i번째 정점이 선택되지 않았고, dist[i] < dist[v]이면 v = i
		return v;
}

void prim(Prim_graph* g, int s)
{
	int i, u, v;
	for (u = 0; u < g->n; u++)
	{
		distance[u] = INF;
	}
	distance[s] = 0;
	for (i = 0; i < g->n; i++)
	{
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		printf("정점 %d 선택\n", u);
		for (v = 0; v < g->n; v++)
		{
			if (!selected[v] && g->weight[u][v] != INF) //  u번쨰 정점과 인접한 정접을 찾음
			{
				if (g->weight[u][v] < distance[v]) // 더 작은 가중치에 연결함.
				{
					distance[v] = g->weight[u][v]; // dist[v] 에 가중치 저장
				}
			}
		}
	}
}

int main()
{
	Prim_graph g = { 7,
		{ { 0, 29, INF, INF, INF, 10, INF },
		  { 29, 0, 16, INF, INF, INF, 15 },
		  { INF, 16, 0, 12, INF, INF, INF },
		  { INF, INF, 12, 0, 22, INF, 18 },
		  { INF, INF, INF, 22, 0, 27, 25 },
		  { 10, INF, INF, INF, 27, 0, INF },
		  { INF, 15, INF, 18, 25, INF, 0 } }
	};
	prim(&g, 0);
	return 0;
}