#include <iostream>

#define INF 100000001

using namespace std;

int g[101][101];


int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			g[i][j] = INF;
		g[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, val;
		cin >> a >> b >> val;
		if (g[a - 1][b - 1] > val) g[a - 1][b - 1] = val;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j] > g[i][k] + g[k][j]) 
					g[i][j] = g[i][k] + g[k][j];
			}
		}
	}


	// Ãâ·Â
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j] == INF) cout << 0 << " ";
			else cout << g[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}