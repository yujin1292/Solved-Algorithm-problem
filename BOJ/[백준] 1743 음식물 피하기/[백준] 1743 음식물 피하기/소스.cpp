#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 101;

int map[MAX][MAX]; // 전역변수는 0으로 초기화
int visited[MAX][MAX];
int N, M, K;
int dc[4] = { 1,-1,0,0 };
int dr[4] = { 0,0,-1,1 };
int answer = -1;

void bfs(int row, int col) {
	queue<pair<int, int>> q;

	int area = 1;

	visited[row][col] = 1;
	q.push(make_pair(row, col));


	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();


		for (int dir = 0; dir < 4; dir++) {
			int nextRow = cur.first + dr[dir];
			int nextCol = cur.second + dc[dir];

			if (visited[nextRow][nextCol]) continue;
			if (nextRow > N || nextRow <= 0) continue;
			if (nextCol > M || nextCol <= 0) continue;
			if (map[nextRow][nextCol] == 0) continue;
			
			q.push(make_pair(nextRow, nextCol));
			visited[nextRow][nextCol] = 1;
			area++;
		}

	}


	if (answer < area) answer = area;
}

int main() {

	cin >> N >> M >> K;

	
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;

		map[x][y] = 1; //쓰레기
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visited[i][j]) continue;
			if( map[i][j] == 0) continue;
			bfs(i, j);
		}
	}
	
	cout << answer;

	return 0;
}