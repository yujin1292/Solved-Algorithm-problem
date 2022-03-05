#include <iostream>
#include <vector>
#include <queue>
#include <string>


#define MAX 1001

using namespace std;

int n,m, inDegree[MAX];
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;

	//진입차수가 0 인 노드를 큐에 삽입한다
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		// n 개를 방문하기 전에 큐가 비어버리면 사이클이 발생한것
		if (q.empty()) {
			cout << 0 << endl;
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];

			//새롭게 진입차수가 0이 된 정점을 큐에 삽입한다.
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << "\n";
	}

}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num, before, now;
		cin >> num >> before;

		for (int j = 1; j < num; j++) {
			cin >> now;
			a[before].push_back(now);
			inDegree[now]++;
			before = now;
		}
	}

	topologySort();

	return 0;
}