#include <iostream>
#include <vector>

using namespace std;

int N, S;

int const MAX = 21;

int numbers[MAX];
int ans = 0;

void dfs(int v, int cnt, int sum) {

	if (v == N) { // 수열완성 
		if (sum == S) { //합이 S가 되면 값올리기
			if (cnt != 0) { //공집합인가?
				ans++;
			}
		}
		return;
	}
	

	dfs(v + 1, cnt, sum); //선택안함
	dfs(v + 1, cnt + 1, sum + numbers[v]); //선택함

	return;
}


int main() {


	cin >> N >> S;

	// N개의 정수로 이루어진 수열
	// 부분수열중에 합이 S 인 개수
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		numbers[i] = temp;
	}

	// 부분수열 찾기

	dfs(0, 0, 0);
		
	cout << ans << endl;

}