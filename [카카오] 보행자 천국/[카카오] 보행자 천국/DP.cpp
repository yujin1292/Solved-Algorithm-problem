#include <vector>
#include <iostream>
#define MAX 501
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
	int right[MAX][MAX];
	int down[MAX][MAX];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			right[i][j] = 0;
			down[i][j] = 0;
		}
	}

	for (int x = 1; x <= m; x++) {
		for (int y = 1; y <= n; y++) {
			int state = city_map[x - 1][y - 1];

			if ((x == 1) && (y == 1)) {
				right[x][y] = down[x][y] = 1;
				continue;
			}
			if (state == 0)
				right[x][y] = down[x][y] = (right[x][y - 1] + down[x - 1][y]) % MOD;
			else if (state == 1)
				right[x][y] = down[x][y] = 0;
			else if (state == 2) {
				right[x][y] = right[x][y - 1];
				down[x][y] = down[x - 1][y];
			}

		}
	}
	return right[m][n];
}



int main() {

	cout << solution(3, 6, {{0, 2, 0, 0, 0, 2},{0, 0, 2, 0, 1, 0},{1, 0, 0, 2, 2, 0} }) << endl;

}