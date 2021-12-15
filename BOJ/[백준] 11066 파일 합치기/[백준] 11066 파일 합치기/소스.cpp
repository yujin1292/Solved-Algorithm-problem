#include <iostream>
#include <algorithm>

#define MAX 501
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

const int INF = 987654321;
int numbers[MAX];
int costs[MAX];
int dp[MAX][MAX];

int main() {
	int T;
	cin >> T;

	while (T--) {
		int num;
		cin >> num;

		for (int i = 1 ; i <= num; i++) {
			cin >> numbers[i];
			costs[i] = costs[i - 1] + numbers[i];
		}


		for (int i = 1 ; i < num; i++) {
			for (int j = 1; j + i <= num; j++) {
				dp[j][j + i] = INF;

				for (int k = j; k <= j + i; k++) {
					dp[j][j + i] = min(dp[j][j + i]
						, dp[j][k] + dp[k + 1][j + i] + costs[j + i] - costs[j - 1]);
				}
			}
		}
		cout << dp[1][num] << "\n";
	}
	return 0;
}