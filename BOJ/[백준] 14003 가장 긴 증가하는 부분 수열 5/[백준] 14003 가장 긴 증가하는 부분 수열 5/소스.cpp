#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;


int n, first, k;

vector <int> lis;
vector < pair<int, int> > arr; // {원본 배열 값, LIS에서 인덱스 }
// 추적 가능하게 만들 것 !

int main(void) {
	fastio;

	cin >> n;
	cin >> first;
	lis.push_back(first);
	arr.push_back({ first, 0 });
	for (int i = 1; i < n; i++) {
		cin >> k;

		if (lis.back() >= k) {
			auto lowerBound = lower_bound(lis.begin(), lis.end(), k);
			*lowerBound = k;
			int idx = lowerBound - lis.begin();
			arr.push_back({ k,idx });
		}
		else {
			lis.push_back(k);
			arr.push_back({ k, lis.size() - 1 });
		}
	}

	stack<int> result;
	int count = lis.size()-1;
	for (int i = arr.size() - 1; i >= 0; i--) {
		if (arr[i].second == count) {
			result.push(arr[i].first);
			count--;
		}
	}

	// 답 출력
	cout << lis.size() << endl;
	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}

	return 0;
}