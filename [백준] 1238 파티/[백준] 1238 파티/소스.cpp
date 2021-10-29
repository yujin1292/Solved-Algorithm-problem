#include <iostream>
#define INF 98765643
using namespace std;

int g[1001][1001];

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			g[i][j] = INF;
		}
		g[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int a, b, val;
		cin >> a >> b >> val;
		g[a][b] = val;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (g[i][k] + g[k][j] < g[i][j])
					g[i][j] = g[i][k] + g[k][j];
			}
		}
	}

	int maxDistance = -1;
	for (int i = 1; i <= N; i++) {
		if (maxDistance < g[i][X] + g[X][i])
			maxDistance = g[i][X] + g[X][i];
	}

	cout << maxDistance << endl;

	return 0;
}