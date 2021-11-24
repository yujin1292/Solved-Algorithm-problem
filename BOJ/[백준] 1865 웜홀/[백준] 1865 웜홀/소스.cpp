#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321

using namespace std;

int t, n, m, w, a, b, c, cycle;
int dist[505];
vector<vector<int>> edges;

int main() {
	cin >> t;
	while (t--) {
		cycle = false;
		cin >> n >> m >> w;
		edges.clear();
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			edges.push_back({ a,b,c });
			edges.push_back({ b,a,c });
		}
		for (int i = 0; i < w; i++) {
			cin >> a >> b >> c;
			edges.push_back({ a,b,c * -1 });
		}
		
		
		dist[1] = 0;
		for (int i = 2; i <= n; i++)
			dist[i] = INF;

		for (int i = 1; i <= n; i++) {			
			//모든 간선에 대해서 edge relaxation
			for (auto edge : edges) {
				int start = edge[0];
				int end = edge[1];
				int cost = edge[2];

				if (dist[start] + cost < dist[end]) {
					dist[end] = dist[start] + cost; // update!
					if (i == n) cycle = true;
				}
			}
		}
		if (cycle)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}