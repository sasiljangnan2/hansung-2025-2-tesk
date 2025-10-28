#include <stdio.h>
#include <stdlib.h>
 
#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];


struct Edge {
	int start, end, weight;
};
int compare(const void* a, const void* b) {
	struct Edge* edge1 = (struct Edge*)a;
	struct Edge* edge2 = (struct Edge*)b;
	return edge1->weight - edge2->weight;
}

typedef struct Graph {
	int n; // 간선 수
	struct Edge edges[2 * MAX_VERTICES];
} Graph;
void set_init() {
	for ( int i = 0; i < MAX_VERTICES; i++) {
		parent[i] = -1;
	}
}

void graph_init(Graph* g) {
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}
void insert_edge(Graph* g, int s, int e, int w) {
	g->edges[g->n].start = s;
	g->edges[g->n].end = e;
	g->edges[g->n].weight = w;
	g->n++;
}
int set_find(int v) {
	if (parent[v] == -1)
		return v;
	return set_find(parent[v]);
}
void set_union(int u, int v) {
	int root1 = set_find(u);
	int root2 = set_find(v);
	if (root1 != root2) {
		parent[root2] = root1;
	}
}
void kruskal(Graph* g, int n)
{
	int edge_accepted = 0;
	int uset, vset;
	struct Edge e;
	int i = 0;
	qsort(g->edges, g->n, sizeof(struct Edge), compare);
	while (edge_accepted <= n - 1)
	{
		e = g->edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);
		if (uset != vset)
		{
			printf("간선 (%d, %d) 가 선택되었습니다. 가중치: %d\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);
		}
		i++;
	}
}
int main(void)
{
	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));

	int v = 7;
	set_init();
	graph_init(g);
	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);
	kruskal(g, v);
}