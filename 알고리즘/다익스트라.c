#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 7
#define INF 1000000

typedef struct graphtype{
	int n; // 정점의수
	int weight[MAX_VERTICES][MAX_VERTICES];
}graphtype;
int distance[MAX_VERTICES];
int found[MAX_VERTICES];
void printf_status()
{
	static int step = 0;
	printf("STEP %2d: \n", step++);
	printf("distance: ");
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		if (distance[i] == INF)
			printf("  * ");
		else
			printf("%3d ", distance[i]);
	}
	printf("\nfound: ");
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		printf(" %d ", found[i]);
	}
	printf("\n\n");
}
int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (int i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}
void shortest_path(graphtype* g, int start)
{
	for (int i = 0; i < g->n; i++)
	{
		found[i] = FALSE;
		distance[i] = g->weight[start][i];
	}
	found[start] = TRUE;
	distance[start] = 0;
	
	for (int i = 0; i < g->n; i++)
	{
		int u = choose(distance, g->n, found);
		found[u] = TRUE;

		for (int w = 0; w < g->n; w++)
		{
			if (!found[w])
			{
				if (distance[u] + g->weight[u][w] < distance[w])
				{
					distance[w] = distance[u] + g->weight[u][w];
				}
			}
		}
		printf_status();
	}
}
int main(void)
{
	graphtype g = { 7,
		{{0, 7, INF, INF, 3, 10, INF},
		{7, 0, 4, 10, 2, 6, INF},
		{INF, 4, 0, 2, INF, INF, INF},
		{INF, 10, 2, 0, 11, 9, 4},
		{3, 2, INF, 11, 0, INF, 5},
		{10, 6, INF, 9, INF, 0, INF},
		{INF, INF, INF, 4, 5, INF, 0}
		}
	};

	shortest_path(&g, 0);
	
}