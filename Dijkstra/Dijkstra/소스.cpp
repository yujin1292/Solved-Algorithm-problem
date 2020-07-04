#include <stdio.h>

#define N 100
#define INF 100000

int map[N + 1][N + 1];
int visit[N + 1];
int dist[N + 1];
int vertex;
int edge;
int start;
int end;

void dijkstra(void)
{
	int i;
	int j;
	int min;
	int v;

	dist[start] = 0;

	for (i = 1; i <= vertex; i++)
	{
		min = INF;

		for (j = 1; j <= vertex; j++)
		{
			if (visit[j] == 0 && min > dist[j])
			{
				min = dist[j];
				v = j;
			}
		}

		visit[v] = 1;

		for (j = 1; j <= vertex; j++)
		{
			if (dist[j] > dist[v] + map[v][j])
			{
				dist[j] = dist[v] + map[v][j];
			}
		}
	}
}

int main(void)
{
	int test_case;
	int T;
	int i;
	int j;
	int from;
	int to;
	int value;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d %d %d", &vertex, &start, &end);
		scanf("%d", &edge);

		for (i = 1; i <= vertex; i++)
		{
			for (j = 1; j <= vertex; j++)
			{
				if (i != j)
				{
					map[i][j] = INF;
				}
			}
		}

		for (i = 1; i <= edge; i++)
		{
			scanf("%d %d %d", &from, &to, &value);
			map[from][to] = value;
		}

		for (i = 1; i <= vertex; i++)
		{
			dist[i] = INF;
			visit[i] = 0;
		}

		printf("#%d ", test_case);
		dijkstra();
		printf("%d \n", dist[end]);
	}
	return 0;
}

/*

1 // test case 개수
7 1 7 // 정점의 개수, 그리고 시작 정점, 도착 정점
9 // 간선 개수
1 2 4 // 1->2, 비용은 4
1 3 2
2 4 1
2 5 2
3 4 7
3 6 3
4 7 3
5 7 1
6 7 5

*/
