#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define MOD 1000000007

using namespace std;

long long road[100][100];

int solution(int m, int n, vector<vector<int>> puddles) {
	for (int i = 0; i < puddles.size(); i++) //¿õµ¢ÀÌ Ã¼Å©
		road[puddles[i][1] - 1][puddles[i][0] - 1] = -1;

	road[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (road[i][j] < 0)
				continue;
			if (i == 0 && j == 0)
				continue;
			if (i == 0)
				road[i][j] = road[i][j - 1];
			else if (j == 0)
				road[i][j] = road[i - 1][j];
		}
	}



	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (road[i][j] < 0) //¿õµ¢ÀÌ
				continue;

			// ¿õµ¢ÀÌ ¾Æ´Ô
			long long  a = road[i][j - 1] < 0 ? 0 : road[i][j - 1];
			long long  b = road[i - 1][j] < 0 ? 0 : road[i - 1][j];
			road[i][j] = (a + b) % MOD;
		}
	}

	return road[n - 1][m - 1];
}

int main() {

	

	cout << solution(4, 3, { {2,2} });
}