#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int a[1000001];
/* ���� : https://suhwanc.tistory.com/58 */
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
		if (s.empty()) { //�ʱ� ��
			s.push(i);
		}

		while (!s.empty() && a[s.top()] < a[i]) { //��ū�� �߰� ��
			answer[s.top()] = a[i];
			s.pop();
		}
		s.push(i); 
	}

	while (!s.empty()) { //¦�� ã�� ���� ���̵�
		answer[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}
