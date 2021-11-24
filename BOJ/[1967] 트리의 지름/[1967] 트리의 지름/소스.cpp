#include <iostream>
#include <memory.h>

using namespace std;

char visit[10001];
char G[10001][10001];
int N;

int max_d = -1;
int max_v;


void find(int v, int distance) {
	if (max_d < distance) {
		max_d = distance;
		max_v = v;
	}

	for (int i = 1; i <= N; i++) {		
		if (G[v][i] == 0) continue;
		if (visit[i]) continue;

		visit[i] = 1;
		find(i, distance + G[v][i]);
		visit[i] = 0;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N-1; i++) {
		int a, b, val;
		cin >> a >> b >> val;
		G[a][b] = val;
		G[b][a] = val;
	}

	// 1번 노드에서 가장 먼 t 찾기

	visit[1] = 1;
	find(1, 0);
	// t에서 가장 먼거리 찾기
	memset(visit, 0, N * sizeof(char));
	int t = max_v;
	max_d = -1;
	visit[t] = 1;
	find(t, 0);

	cout << max_d << endl;

	return 0;
}