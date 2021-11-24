#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int visit[MAX];
int max_d = -1;
int max_v;

vector<pair<int,int> > tree[MAX];

void dfs(int v , int dis) { //가장 먼곳 반환
	
	if (max_d < dis) {
		max_d = dis;
		max_v = v;
	}

	for (int i = 0; i < tree[v].size(); i++) {
		if (visit[tree[v][i].first])
			continue;
		visit[tree[v][i].first] = 1;
		dfs(tree[v][i].first, tree[v][i].second + dis);
		visit[tree[v][i].first] = 0;
	}
}

int main() {
	int V, v, vv , distance, t, u;
	cin >> V;
	//입력
	for (int i = 0; i < V; i++) {
		cin >> v;
		while (true) {
			cin >> vv;
			if (vv == -1) break;
			cin >> distance;
			tree[v].push_back({ vv,distance });
		}
	}
	
	// step1) 1에서 가장 먼 t 찾기
	visit[1] = 1;
	dfs(1,0);
	visit[1] = 0;

	// step2) t에서 가장 먼 거리찾기
	t = max_v;
	max_d = -1;
	visit[t] = 1;
	dfs(t,0);
	
	cout << max_d << endl;

	return 0;
}