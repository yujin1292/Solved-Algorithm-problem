// 출처 : https://blog.naver.com/mr4454/222521120416

#include <iostream>
#include <vector>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, first, k;
vector <int> vec;

int main(void) {
	fastio;

	cin >> n;
	// 첫 수는 무조건 push
	cin >> first;
	vec.push_back(first);

	// vec 에 담기는 수는 실질적인 LIS 가 아니지만, 길이는 충분히 구할 수있음
	for (int i = 1; i < n; i++) {
		cin >> k;
		if (vec.back() >= k) { 
			auto lowerBound = lower_bound(vec.begin(), vec.end(), k);
			*lowerBound = k;
		}
		else {
			vec.push_back(k);
		}
		//for (auto v : vec)
		//	cout << v << " ";
		//cout << endl;
	}

	cout << vec.size();

	return 0;
}