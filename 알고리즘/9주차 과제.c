#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

// 크루스칼 알고리즘
int parent[MAX_VERTICES];

// 프림 알고리즘
int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

// 간선 배열 (시작 정점, 끝 정점, 가중치) 
int arr[MAX_VERTICES][MAX_VERTICES] = { {0, 1, 29},
				 {1, 2, 16},
				 {2, 3, 12},
				 {3, 4, 22},
				 {4, 5, 27},
				 {5, 0, 10},
				 {6, 1, 15},
				 {6, 3, 18},
				 {6, 4, 25} }; 

// 크루스칼 알고리즘
struct Edge {
	int start, end, weight;
};
int compare(const void* a, const void* b) {
	struct Edge* edge1 = (struct Edge*)a;
	struct Edge* edge2 = (struct Edge*)b;
	return edge1->weight - edge2->weight;
}

typedef struct Kruskal_graph {
	int n; // 간선 수
	struct Edge edges[2 * MAX_VERTICES];
} Kruskal_graph;
void set_init() //초기화 
{
	for (int i = 0; i < MAX_VERTICES; i++) {
		parent[i] = -1;
	}
}

void Kruskal_graph_init(Kruskal_graph* g)
{
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}
void insert_edge(Kruskal_graph* g, int s, int e, int w)
{
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
void kruskal(Kruskal_graph* g, int n)
{
	int edge_accepted = 0;
	int uset, vset;
	struct Edge e;
	int i = 0;
	qsort(g->edges, g->n, sizeof(struct Edge), compare);
	while (edge_accepted < n - 1)
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

// 프림 알고리즘
typedef struct Prim_graph {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}Prim_graph;

int get_min_vertex(int n) // 최소 dist[v] 값을 갖는 정점 변환
{
	int v, i;

	for (i = 0; i < n; i++)
	{
		if (!selected[i]) // 선택되지 않은 정점 찾기
		{
			v = i;
			break;
		}
	}
	for (i = 0; i < n; i++) if (!selected[i] && distance[i] < distance[v]) v = i; // i번째 정점이 선택되지 않았고, dist[i] < dist[v]이면 v = i
	return v;
}

void Prim_graph_init(Prim_graph* g, int n) //프림 그래프 초기화
{
	g->n = n;
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		for (int j = 0; j < MAX_VERTICES; j++)
		{
			g->weight[i][j] = INF;
		}
	}
}
void prim(Prim_graph* g, int s)
{
	int i, u, v;
	for (u = 0; u < g->n; u++) // distance 배열 초기화
	{
		distance[u] = INF;
	}
	distance[s] = 0; // 시작 정점의 거리는 0
	for (i = 0; i < g->n; i++)
	{
		u = get_min_vertex(g->n); // 최소 거리의 정점 u 선택
		selected[u] = TRUE; 
		printf("정점 %d 선택\n", u);
		for (v = 0; v < g->n; v++)
		{
			if (!selected[v] && g->weight[u][v] != INF) // u번쨰 정점과 인접한 정접을 찾음
			{
				if (g->weight[u][v] < distance[v]) // 인접 하면
				{
					distance[v] = g->weight[u][v]; // dist[v] 에 가중치 저장
					printf("정점 %d 와 정점 %d 의 거리: %d\n", u, v, distance[v]);
				}
			}
		}
	}
}

void Kruskal_insert(Kruskal_graph* g, int v) // 크루스칼 그래프에 간선 삽입
{
	for (int i = 0; i < v; i++)
	{
		insert_edge(g, arr[i][0], arr[i][1], arr[i][2]);
	}
}

void Prim_insert(Prim_graph* g, int n) // 프림 그래프에 간선 삽입
{
	for (int i = 0; i < n; i++)
	{
		g->weight[arr[i][0]][arr[i][1]] = arr[i][2];
		g->weight[arr[i][1]][arr[i][0]] = arr[i][2];
		g->weight[i][i] = 0;
	}
}
int select() // 정점과 간선의 값 지정하는 함수, 정점의 개수 리턴
{
	int choice, v;
	printf("1. 저장되어 있는 값을 사용합니다.\n");
	printf("2. 직접 값을 입력합니다.\n");
	printf("선택: ");
	scanf("%d", &choice);
	if (choice == 1)
	{
		v = 9;
		return v;
	}
	else if (choice == 2) {
		printf("정점의 개수: ");
		scanf("%d", &v);
		for (int i = 0; i < v; i++)
		{
			int a, b, w;
			printf("정점 2개를 잇는 간선과 가중치를 입력하세요. 예시: 1 2 29\n");
			scanf("%d %d %d", &a, &b, &w);
			arr[i][0] = a;
			arr[i][1] = b;
			arr[i][2] = w;
		}
		return v;
	}
}
void print_Num(int v)
{
	for (int i = 0; i < v; i++)
	{
		printf("정점 %d - 정점 %d: 가중치 %d\n", arr[i][0], arr[i][1], arr[i][2]);
	}
}
void menu()
{
	printf("1. 크루스칼 알고리즘\n");
	printf("2. 프림 알고리즘\n");
	printf("3. 저장되어 있는 값 확인\n");
	printf("4. 종료\n");
	printf("선택: ");
}

int main()
{
	system("COLOR F0"); // 흰바탕 검은 글씨
	int choice;
	int v;
	v = select();
	while (1)
	{
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: // 크루스칼 알고리즘
			Kruskal_graph *kg;
			kg = (Kruskal_graph*)malloc(sizeof(Kruskal_graph));
			set_init();
			Kruskal_graph_init(kg);
			Kruskal_insert(kg, v);
			kruskal(kg, 7);
			break;
		case 2: // 프림 알고리즘
			Prim_graph * pg;
			pg = (Prim_graph*)malloc(sizeof(Prim_graph));
			Prim_graph_init(pg, 7);
			Prim_insert(pg, v);
			prim(pg, 0);
			break;
		case 3: // 저장되어 있는 값 확인
			print_Num(v);
			break;
		case 4: // 종료
			exit(0);
			break;
		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
	
	return 0;
}