#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_V = 1001;
const int INF = 100001; // 최대거리 100 x 최대 마을수 1,000 + 1

struct edge {
	int to;
	int weight;
	bool operator<(const edge& o) const {
		return weight > o.weight;
	}
};

int from_x[MAX_V + 1];
int to_x[MAX_V + 1];
vector<edge> adj_origine[MAX_V + 1];
vector<edge> adj_reversed[MAX_V + 1];

int v, e, x;

void dijkstra(int start , vector<edge> *adj, int*dist )
{
	fill(dist, dist + v + 1 , INF);
	priority_queue<edge> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty())
	{
		edge cur = pq.top();
		pq.pop();

		if (cur.weight > dist[cur.to])
			continue;

		for (edge& nxt : adj[cur.to])
		{
			if (dist[cur.to] + nxt.weight < dist[nxt.to])
			{
				dist[nxt.to] = dist[cur.to] + nxt.weight;
				pq.push({ nxt.to, dist[nxt.to] });
			}
		}
	}

}

int main()
{
	cin >> v >> e >>x;

	for (int i = 0; i < e; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;

		adj_origine[a].push_back({ b, w });
		adj_reversed[b].push_back({ a,w });
	}


	dijkstra(x, adj_reversed ,to_x);
	dijkstra(x, adj_origine, from_x);


	int maxDistance = -1;
	for (int i = 1; i <= v; i++) {
		if (maxDistance < from_x[i] + to_x[i])
			maxDistance = from_x[i] + to_x[i];
	}

	cout << maxDistance << endl;

	return 0;
}