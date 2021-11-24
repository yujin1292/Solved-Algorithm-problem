#include <iostream>
#include <queue>
#include <map>
using namespace std;


map<long long, bool> visit;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	queue<long long> q;
	q.push(A);
	int result = 0;

	while (!q.empty()) {
		result++;
		int qsize = q.size();

		while (qsize--) {

			long long cur = q.front();
			q.pop();

			// 2곱하기
			long long next = cur * 2;
			if (next > B || visit[next]) continue;
			if (B == next) {
				cout << result + 1 << endl;
				return 0;
			}
			visit[next] = 1;
			q.push(next);

			// 1붙이기
			next = cur * 10 + 1;
			if (next > B || visit[next]) continue;
			if (B == next) {
				cout << result + 1 << endl;
				return 0;
			}
			visit[next] = 1;
			q.push(next);
		}
	}
	cout << -1 << endl;
	return 0;
}