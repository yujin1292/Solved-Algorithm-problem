
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_V = 1001;
const int INF = 100001; 

struct info {
	int to;
	int weight;
	bool operator<(const info& o) const {
		return weight > o.weight;
	}
};

int n, m, r;

int dist[MAX_V];
int item[MAX_V];
vector<info> adj[MAX_V + 1];
int answer = 0;

void dijkstra(int start)
{
	fill(dist, dist + n + 1, INF);
	priority_queue<info> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty())
	{
		info cur = pq.top();
		pq.pop();

		if (cur.weight > dist[cur.to])
			continue;

		for (info& nxt : adj[cur.to])
		{
			if (dist[cur.to] + nxt.weight < dist[nxt.to])
			{
				dist[nxt.to] = dist[cur.to] + nxt.weight;
				pq.push({ nxt.to, dist[nxt.to] });
			}
		}
	}

	int gets = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] <= m) gets += item[i];
	}

	if (answer < gets) answer = gets;
}

int main(){

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	for (int i = 0; i < r; i++){
		int a, b, l;
		cin >> a >> b >> l;
		
		adj[a].push_back({ b,l });
		adj[b].push_back({ a,l });
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}

	cout << answer;

	return 0;

}
