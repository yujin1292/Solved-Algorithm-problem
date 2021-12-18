#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAX = 1001;
const int INF = 987654321;

int cost[MAX][3];
pair<int, int> dp[MAX][3];

int N;

int getMinCost(int start) {
	for (int i = 2; i <= N; i++) {
		for (int color = 0; color < 3; color++) {
			dp[i][color] = { -1,INF };

			if (i == 2) {
				int prevColor = start;
				if (prevColor == color) continue;
				if (dp[i][color].second > dp[i - 1][prevColor].second + cost[i][color]) 
					dp[i][color] = { prevColor,  dp[i - 1][prevColor].second + cost[i][color] };			
			}
			else {
				if (i == N && color == start) continue;

				for (int dc = 1; dc <= 2; dc++) {
					int prevColor = (color + dc) % 3;

					if (dp[i][color].second > dp[i - 1][prevColor].second + cost[i][color]) 
						dp[i][color] = { prevColor,  dp[i - 1][prevColor].second + cost[i][color] };
					
				}

			}
		}
	}

	return min(dp[N][0].second, min(dp[N][1].second, dp[N][2].second));
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int color = 0; color < 3; color++)
			cin >> cost[i][color];

	dp[1][0] = { 0,cost[1][0] };
	dp[1][1] = { 1,cost[1][1] };
	dp[1][2] = { 2,cost[1][2] };

	int answer = INF;
	for (int start = 0; start < 3; start++) {
		answer = min(answer, getMinCost(start));
	}

	cout << answer;
	return 0;
}

/*

3

13 89 99

49 60 57

26 40 83

정답: 110


2

1000 1000 1

1000 1000 1

정답: 1001



*/