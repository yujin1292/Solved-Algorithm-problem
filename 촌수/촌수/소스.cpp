#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 100

using namespace std;
int visit[MAX];
queue< pair<int, int> > q;
vector<int>  G[MAX];

int main() {

	int family, a, b, edge;

	cin >> family >> a >> b >> edge;

	int t1, t2;

	for (int i = 0; i < edge; i++) { // 입력
		cin >> t1 >> t2;

		G[t2].push_back(t1);
		G[t1].push_back(t2);

	}


	q.push({ a,0 }); //시작점 1, 촌수 0으로시작
	visit[a] = 1;

	while (!q.empty()) {
		
		int cur = q.front().first;
		int distance = q.front().second;

		if (cur == b) {
			cout << distance << endl;
			return 0;
		}

		for (int i = 0; i < G[cur].size(); i++) {
			if (visit[G[cur][i]])
				continue;
			q.push({ G[cur][i], distance + 1 } );
			visit[G[cur][i]] = 1;
		}

		q.pop();

	}
	cout << -1 << endl;

	return 0;
}