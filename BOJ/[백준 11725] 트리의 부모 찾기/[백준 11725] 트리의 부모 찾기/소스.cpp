#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int visit[100001];


int main() {
	int n;
	cin >> n;
	vector<vector<int> > g;
	vector<int> parent;

	g.resize(n+1);
	parent.resize(n+1);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	//bfs start from 1
	
	queue<int> q;
	q.push(1);
	visit[1] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			if (visit[next]) continue;
			
			visit[next] = 1;
			parent[next] = cur;

			q.push(next);
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}