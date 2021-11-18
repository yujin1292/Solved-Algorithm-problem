#include<iostream>
#include<queue>
#define MAX 100001
using namespace std;

int n, k;
const int dx[2] = { -1, 1 };
bool visited[MAX];
queue<pair<int, int>> q;

int main() {
	cin >> n >> k;

	q.push({ n, 0 });
	visited[n] = 1;

	for (int i = 2; i * n <= MAX + 1; i *= 2) {
		if (n == 0) break;
		q.push({ i * n, 0 });
		visited[i * n] = 1;
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		// ´ä Ã£À½
		if (cur.first == k) {
			cout << cur.second;
			return 0;
		}

		for (int i = 0; i < 2; i++) {
			int next = cur.first + dx[i];

			if (next < 0 || next > MAX ) continue;
			if (visited[next]) continue;

			q.push({ next, cur.second + 1 });
			visited[next] = 1;

			for (int i = next*2 ;  i <= MAX ; i *= 2) {
				if (i == 0) break;
				if (visited[i]) continue;
				q.push({ i, cur.second + 1 });
				visited[i] = 1;
			}
		}
	}
	return 0;
}