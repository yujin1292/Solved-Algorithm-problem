#include <iostream>
#include <algorithm>

using namespace std;

int g[501][501];
int dp[501][501];

int main() {
	int n;
	int temp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> temp;
			g[i][j] = temp;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {			
			int maxValue = max(dp[i - 1][j - 1], dp[i - 1][j]);
			dp[i][j] = maxValue + g[i][j];
		}
	}

	int answer = -1;
	for (int i = 1; i <= n; i++) {
		if (answer < dp[n][i]) answer = dp[n][i];
	}
	cout << answer << endl;
	return 0;
}