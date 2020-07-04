#include <iostream>
#include <vector>

using namespace std;
int const MAX = 5;

int num[MAX] = { -7,-3,-2,5,8 };
int N, S, ans;



// v ->  지금 위치(인덱스)
// sum -> 지금까지의 합
// cnt -> 지금까지 고른 개수

void dfs(int v, int sum, int cnt) {
	if(v == N) {
		if (sum == S && cnt != 0) {
			ans++;// 정답 개수 ++
		}
		return;
	}
	dfs(v + 1, sum + num[v], cnt + 1); //선택함
	dfs(v + 1, sum, cnt);  // 선택안함
}

int main() {
	S = -2;
	N = 5;

	dfs(0, 0, 0);

	cout << ans << endl;

	return 0;
}