#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long

using namespace std;

const int MAX = 1001;
const ll INF = 1000 * 100000 + 2;
int N, M, start, dest;

struct edge {
	int to;
	ll weight;
	bool operator<(const edge& o) const {
		return weight > o.weight;
	}
};

vector<edge> v[MAX]; // v[a] = (b,c) : a에서 b까지 c의  비용으로 이동 가능

ll dist[MAX];
vector<int> route[MAX];


void dijkstra(int start) {

	fill(dist, dist + N + 1, INF);
	priority_queue<edge> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty())
	{
		edge cur = pq.top();
		pq.pop();

		if (cur.weight > dist[cur.to]) // start -> cur
			continue;

		for (edge& nxt : v[cur.to])
		{
			// [start -> cur + cur -> next]  vs  [start-> next]
			if (dist[cur.to] + nxt.weight < dist[nxt.to])
			{
				// 최단거리 갱신
				dist[nxt.to] = dist[cur.to] + nxt.weight;
				pq.push({ nxt.to, dist[nxt.to] });

				// 경로 갱신
				route[nxt.to] = { route[cur.to].begin(), route[cur.to].end() };
				route[nxt.to].push_back(nxt.to);

			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int s, d, cost;
		cin >> s >> d >> cost;
		v[s].push_back({ d,cost });
	}
	cin >> start >> dest;

	dijkstra(start);
	

	cout << dist[dest] << "\n";
	cout << route[dest].size()+1 << "\n";
	cout << start << " ";
	for (int v : route[dest])
		cout << v << " ";

	cout << endl;
	return 0;
}