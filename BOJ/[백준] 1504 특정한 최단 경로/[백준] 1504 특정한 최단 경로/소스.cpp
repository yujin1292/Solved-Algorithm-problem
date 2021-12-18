#include <iostream>
#include <math.h>
#define ll long long 

using namespace std;

const int MAX = 801;
const int INF = 1000*200*1000;

int g[MAX][MAX];
bool visit[MAX];
int d[MAX];

int N, M;
int v1, v2;

int getSmalIndex() {
	int min = INF;
	int index = 0;

	for (int i = 0; i < N; i++) {
		if (!visit[i] && d[i] < min) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < N; i++) {
		d[i] = g[start][i];
		visit[i] = false;
	}

	visit[start] = true;
	d[start] = 0;

	for (int i = 0; i < N ; i++) {
		int current = getSmalIndex();
		visit[current] = true;
		for (int j = 0; j < N; j++) {
			if (visit[j]) continue;

			if (d[current] + g[current][j] < d[j])
				d[j] = d[current] + g[current][j];
		}
	}
}

int main() {
	int source, dest, distance;

	cin >> N >> M;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			g[i][j] = INF;
	
	for (int i = 0; i < M; i++) {
		cin >> source >> dest >> distance;
		source--;
		dest--;
		g[source][dest] = g[dest][source] = distance;
	}
	
	cin >> v1 >> v2;
	v1--;
	v2--;

	dijkstra(0);
	ll one_v1 = d[v1];
	ll one_v2 = d[v2];

	dijkstra(v1);
	ll v1_v2 = d[v2];
	ll v1_N = d[N - 1];

	dijkstra(v2);
	ll v2_N = d[N -1];

	ll res = INF;
	res = min(res, one_v1 + v1_v2 + v2_N);
	res = min(res, one_v2 + v1_v2 + v1_N);

	if (res == INF) cout << -1;
	else cout << res;

	return 0;
}