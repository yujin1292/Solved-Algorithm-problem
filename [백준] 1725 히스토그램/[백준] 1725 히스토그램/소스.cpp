#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);


using namespace std;

vector<int> h;
int N;


int solve(int left, int right) {

	if (left == right) return h[left];

	int mid = (left + right) / 2;
	// 좌측 우측 계산
	int ret = max(solve(left, mid), solve(mid + 1, right));

	// 중간에 걸쳐있는 경우 계산
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2); // 최솟값

	while (left < lo || hi < right) { //더 넓게 만들어갈수있는지 계속 진행
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			hi++;
			height = min(height, h[hi]);
		}
		else {
			lo--;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}

	return ret;
}


int main() {
	fastio;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		h.push_back(temp);
	}

	cout << solve(0, N - 1);

	return 0;
}