#include <iostream>
#include <vector>
#include <queue>


using namespace std;

#define MAX 100000

vector<int> G[MAX + 1];
int visit[MAX + 1];
int N, K;


bool inRange(int a) {
	return (0 <= a && a <= MAX);
}

void solveBFS() {
	queue<int> q;
	int next;
	int curr;
	q.push(N);
	visit[N] = 1;

	int second = 0;
	while (!q.empty()) {

		int qsize = q.size();
		while (qsize--) {
			curr = q.front();
			q.pop();

			if (curr == K) {
				cout << second << "\n";
			}

			next = curr + 1;
			if (inRange(next)) {
				if (!visit[next]) {
					q.push(next);
					visit[next] = 1;
				}
			}

			next = curr - 1;
			if (inRange(next)) {
				if (!visit[next]) {
					q.push(next);
					visit[next] = 1;
				}
			}

			next = 2 * curr;
			if (inRange(next)) {
				if (!visit[next]) {
					q.push(next);
					visit[next] = 1;
				}
			}
		}
		second++;

	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;


	solveBFS();

	return 0;
}