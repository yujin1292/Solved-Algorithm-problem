#include <iostream>
#define MAX 15
using namespace std;

int N, result;

int col[MAX];
int rr[MAX * 2];
int ll[MAX * 2];

void dfs(int x, int y, int count) {

	if (count == N) {
		result++;
		return;
	}

	int nextX = x + 1;
	for (int j = 0; j < N; j++) {
		if (!rr[nextX + j] && !ll[MAX + nextX - j] && !col[j]) {
			col[j] = rr[nextX + j] = ll[MAX + nextX - j] = 1;
			dfs(nextX, j, count + 1); //ij¿¡ queen ³õ±â
			col[j] = rr[nextX + j] = ll[MAX + nextX - j] = 0;
		}
	}
}

int main() {
	cin >> N;
	dfs(-1, -1, 0);
	cout << result << "\n";
}