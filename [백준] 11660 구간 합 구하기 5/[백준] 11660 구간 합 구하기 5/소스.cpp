#include <iostream>
#define MAX 1025
using namespace std;

int N, M;
int dp[MAX][MAX];
int table[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int value;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> value;
			table[i][j] = value;
		}
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			dp[x][y] = dp[x - 1][y] + dp[x][y - 1] - dp[x - 1][y - 1] + table[x][y];
		}
	}


	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result = 0;
		x1--;
		y1--;

		result = dp[x2][y2] - (dp[x1][y2] + dp[x2][y1]) + dp[x1][y1];

		cout << result << "\n";
	}
	return 0;
}