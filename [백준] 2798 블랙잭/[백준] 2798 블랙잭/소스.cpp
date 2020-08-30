#include <iostream>
#define MAX 101
using namespace std;

int N, M;
int ans;
int card[MAX];

void dfs(int v, int sum, int cnt) {
	if (sum > M)
		return;
	if (v == N+1)
		return;
	if (cnt == 3) {
		if (ans < sum) {
			ans = sum;
		}
		return;
	}

	dfs(v + 1, sum, cnt);
	dfs(v + 1, sum + card[v+1], cnt + 1);

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	int c;
	for (int i = 1; i <= N; i++) {
		cin >> c;
		card[i] = c;
	}

	dfs(0, 0, 0);
	cout << ans << endl;
	return 0;
}