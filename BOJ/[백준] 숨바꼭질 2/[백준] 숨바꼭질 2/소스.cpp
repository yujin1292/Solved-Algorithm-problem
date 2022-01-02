#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;

int visited[MAX+1];
int N, K;

bool inRange(int pos) {
	return 0 <= pos && pos <= MAX;
}

int main() {

	cin >> N >> K;

	if (N == K) {
		cout << 0 << "\n" << 1;
		return 0;
	}

	queue<int> q;

	int way = 0;
	int time = 0;
	bool findShortestWay = false;

	q.push(N);
	while (!q.empty()) {
		time++;
		int qsize = q.size();

		while (qsize--) {
			int front = q.front();
			q.pop();

			int next = front + 1;
			if (inRange(next) && (visited[next] == 0 || visited[next] == time)) {
				visited[next] = time;
				q.push(next);
				if (next == K) {
					findShortestWay = true;
					way++;
				}
			}
		

			next = front - 1;
			if (inRange(next) && (visited[next] == 0 || visited[next] == time)) {
				visited[next] = time;
				q.push(next);
				if (next == K) {
					findShortestWay = true;
					way++;
				}
			}

			next = front * 2;
			if (inRange(next) && ( visited[next] == 0 || visited[next] == time )) {
				visited[next] = time;
				q.push(next);
				if (next == K) {
					findShortestWay = true;
					way++;
				}
			}
		}


		if (findShortestWay) {
			cout << time << "\n";
			cout << way << "\n";
			return 0;
		}

	}

	return 0;
}