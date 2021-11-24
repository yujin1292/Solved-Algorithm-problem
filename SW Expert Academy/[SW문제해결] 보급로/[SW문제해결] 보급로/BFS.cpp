#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#define MAX 100

using namespace std;

int time_map[MAX][MAX];
int map[MAX][MAX];
int visit[MAX][MAX];
int dx[] = { 1, 0,-1,0 }; //down right up left
int dy[] = { 0, 1, 0, -1 };

queue<pair<int,int>> q;

int N;
int value;

void init() { //visit 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			time_map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}
bool isValid(int x, int y) {
	if (0 <= x && x < N)
		if (0 <= y && y < N)
			return true;

	return false;
}
bool isVisited(int x, int y) {
	if (visit[x][y] == 1)
		return true;
	return false;
}
void solve() {

	pair<int, int> now;
	int nextX;
	int nextY;

	int curValue;

	q.push({ 0, 0 });
	visit[0][0] = 1;

	while (!q.empty()) {
		int qsize = q.size();

		while (qsize--) {
			now = q.front();
			curValue = time_map[now.first][now.second];
			
			
			for (int i = 0; i < 4; i++) {
				nextX = now.first + dx[i];
				nextY = now.second + dy[i];

				if (isValid(nextX, nextY)) {
					if (!isVisited(nextX, nextY)) { //방문안했음 큐에넣기
						q.push({ nextX, nextY });
						visit[nextX][nextY] = 1;
						time_map[nextX][nextY] = curValue + map[nextX][nextY]; //계산값넣기
					}
					else { //방문했음
						if (time_map[nextX][nextY] > curValue + map[nextX][nextY]) { //전에방문이랑 비교해서
							time_map[nextX][nextY] = curValue + map[nextX][nextY];
							q.push({ nextX, nextY });
						}
					}

				}
			}
			
			

			q.pop();

		}
	}

	value = time_map[N - 1][N - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	string temp;

	cin >> testcase;
	for (int test = 0; test < testcase; test++) {
		cin >> N;
		init();
		for (int i = 0; i < N; i++) {
			cin >> temp;
			for (int j = 0; j < N; j++) {
				map[i][j] = temp[j] - '0';
			}
		}

		solve();
		cout << "#" << test + 1 << " " << value << "\n";
	}

}