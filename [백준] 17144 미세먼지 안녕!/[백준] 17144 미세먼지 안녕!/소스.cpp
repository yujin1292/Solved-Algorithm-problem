#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

int map[1001][1001];
int dc[4] = { 0, 1, 0,-1 };
int dr[4] = { -1,0,1,0 };
int R, C, T, dustInAir;
vector<int> ac;
queue<pair<int, int> > dust;

bool isInRange(int row, int col) {
	return (0 <= row && row < R) && (0 <= col && col < C);
}

bool canGo(int row, int col) {
	return isInRange(row, col) && map[row][col] != -1;
}

bool maintainDirection(int row, int col, int airCleanerIdx) {
	if (airCleanerIdx == 0)  return isInRange(row, col) && row <= ac[airCleanerIdx];
	else  return isInRange(row, col) && row >= ac[airCleanerIdx];
}

void clean(pair<int, int> cur, int airCleanerIdx) {
	int dir = 0;
	dustInAir -= map[cur.first][cur.second];
	while (true) {
		int nextRow = cur.first + dr[dir];
		int nextCol = cur.second + dc[dir];

		if (!maintainDirection(nextRow, nextCol, airCleanerIdx)) {
			dir++; // 방향바꿈
			continue;
		}

		if (nextRow == ac[airCleanerIdx] && nextCol == 0) {
			map[cur.first][cur.second] = 0;
			break;
		}
		else {
			map[cur.first][cur.second] = map[nextRow][nextCol];
			cur = { nextRow,nextCol };
		}
	}
}

void excuteAirCleaner() {
	//윗 쪽 순회
	dr[0] = -1;
	dr[2] = 1;
	clean({ ac[0] - 1, 0 }, 0);

	// 아래 쪽 순회
	dr[0] = 1;
	dr[2] = -1;
	clean({ ac[1] + 1,0 }, 1);
}

void checkDustPos() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (map[i][j] > 0) dust.push({ i,j });
}

int main() {
	// 입력
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] > 0) dustInAir += map[i][j];
			else if (map[i][j] < 0) ac.push_back(i);
		}
	}
	sort(ac.begin(), ac.end());

	// 작업 시작
	while (T--) {
		// 먼지 위치 파악
		checkDustPos();

		// 확산 위치 계산
		vector< pair< pair<int, int>, int > > jobs;
		while (!dust.empty()) {
			auto cur = dust.front();
			dust.pop();

			int count = 0;
			int value = map[cur.first][cur.second] / 5;

			for (int i = 0; i < 4; i++) {
				int nextRow = cur.first + dr[i];
				int nextCol = cur.second + dc[i];

				if (!canGo(nextRow, nextCol)) continue;
				jobs.push_back({ { nextRow,nextCol }, value });
				count++;
			}
			jobs.push_back({ cur, (count * value * -1) });
		}
		
		// 먼지 확산
		for (auto job : jobs) map[job.first.first][job.first.second] += job.second;

		// 공기청정기 작동
		excuteAirCleaner();
	}

	cout << dustInAir << endl;
	return 0;
}