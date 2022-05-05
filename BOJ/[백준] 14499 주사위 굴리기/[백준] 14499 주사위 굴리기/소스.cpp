#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M, r, c, K;

vector<vector<int>> map;

// 주사위 전개도 두 갈래로 나눔
vector<int> horizontal = vector<int>(4, 0);
vector<int> vertical = vector<int>(4, 0);

const int TOP = 0;
const int BOTTOM = 2;

const int EAST = 1;
const int WEST = 2;
const int NORTH = 3;
const int SOUTH = 4;

int dc[5] = { 0, 1, -1, 0, 0 };
int dr[5] = { 0, 0, 0, -1, 1};

bool inRange(int r, int c) {
	if (0 <= r && r < N) {
		if (0 <= c && c < M) return true;
	}
	return false;
}

void rollTheDice(int direction) {

	if (direction == EAST) {
		// shift right - horizontal
		int temp = horizontal[3];
		for (int i = 3; i > 0; i--) {
			horizontal[i] = horizontal[i - 1];
		}
		horizontal[0] = temp;

		vertical[TOP] = horizontal[TOP]; // 동기화
		vertical[BOTTOM] = horizontal[BOTTOM];
	}
	else if (direction == WEST) {
		// shift left - horizontal

		int temp = horizontal[0];
		for (int i = 1; i < 4; i++) {
			horizontal[i - 1] = horizontal[i];
		}
		horizontal[3] = temp;

		vertical[TOP] = horizontal[TOP]; // 동기화
		vertical[BOTTOM] = horizontal[BOTTOM];

	}
	else if (direction == NORTH) {
		// shift left - vertical
		int temp = vertical[0];
		for (int i = 1; i < 4; i++) {
			vertical[i - 1] = vertical[i];
		}
		vertical[3] = temp;

		horizontal[TOP] = vertical[TOP]; // 동기화
		horizontal[BOTTOM] = vertical[BOTTOM];
	}
	else if (direction == SOUTH) {
		// shift right - vertical
		int temp = vertical[3];
		for (int i = 3; i > 0; i--) {
			vertical[i] = vertical[i - 1];
		}
		vertical[0] = temp;

		horizontal[TOP] = vertical[TOP]; // 동기화
		horizontal[BOTTOM] = vertical[BOTTOM];
	}
}

void play(int direction) {
	// move Dice Position
	int nextRow = r + dr[direction];
	int nextCol = c + dc[direction];

	if (!inRange(nextRow, nextCol)) return;

	r = nextRow;
	c = nextCol;

	rollTheDice(direction);


	// copy
	if (map[r][c] == 0) { 
		map[r][c] = vertical[BOTTOM];
	}
	else {
		vertical[BOTTOM]  = map[r][c]; 
		horizontal[BOTTOM] = map[r][c];
		map[r][c] = 0;
	}


	// print Top of dice
	cout << horizontal[TOP] << "\n";
}

int main() {
	cin >> N >> M >> r >> c >> K;

	map = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j< M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int instruction;
		cin >> instruction;
		play( instruction );
	}

	return 0;
}