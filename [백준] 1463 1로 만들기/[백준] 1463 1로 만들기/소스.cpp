#include <iostream>
#include <queue>

using namespace std;

int visit[1000001];

int main() {
	int X;

	cin >> X;


	queue<int> q;
	q.push(X);
	visit[X] = 1;

	int num = 0;

	int cur;

	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			cur = q.front();

			if (cur == 1) {
				cout << num;
				return 0;
			}

			if (cur % 3 == 0) {
				if (!visit[cur / 3]) {
					q.push(cur / 3);
					visit[cur / 3];
				}
			}

			if (cur % 2 == 0) {
				if (!visit[cur / 2]) {
					q.push(cur / 2);
					visit[cur / 2] = 1;
				}
			}
			if (!visit[cur - 1]) {

				q.push(cur - 1);
				visit[cur - 1] = 1;
			}


			q.pop();
			
		}
		num++;
	}

	cout << num;

	return 0;
}