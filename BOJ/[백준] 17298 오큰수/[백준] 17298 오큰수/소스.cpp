#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int a[1000001];
/* 참고 : https://suhwanc.tistory.com/58 */
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> answer(n);
	stack<int> s;
	s.push(0);

	for (int i = 1; i < n; i++) {
		if (s.empty()) { //초기 값
			s.push(i);
		}

		while (!s.empty() && a[s.top()] < a[i]) { //오큰수 발견 시
			answer[s.top()] = a[i];
			s.pop();
		}
		s.push(i); 
	}

	while (!s.empty()) { //짝을 찾지 못한 아이들
		answer[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}
