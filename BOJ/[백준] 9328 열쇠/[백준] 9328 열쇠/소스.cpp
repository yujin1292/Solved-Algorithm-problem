#include <iostream>
#include <algorithm>
#include <string>
#include <queue>


using namespace std;

const int MAX = 100;
const int numOfKey = 'Z' - 'A'+1;


int visited[MAX][MAX];
char map[MAX][MAX];
string keyset;
int keys[numOfKey];
vector<pair<int, int>> doors[numOfKey];


int dc[4] = { 1,0, -1,0 };
int dr[4] = { 0,1,0,-1 };

int answer;
int h, w;


queue<pair<int, int>> q;

void init() {
	answer = 0;

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			visited[i][j] = 0;
			cin >> map[i][j];
		}
	}

	for (char c = 'a'; c <= 'z'; c++) {
		keys[c - 'a'] = 0;
		doors[c - 'a'].clear();
	}

	cin >> keyset;

	if (keyset != "0") {
		for (char c : keyset) {
			keys[c - 'a'] = 1;
		}
	}

}

bool isInRange(int row, int col) {

	if (0 <= row && row < h) {
		if (0 <= col && col < w) {
			return true;
		}
	}

	return false;
}

bool isDoor(int row, int col) {
	if ('A' <= map[row][col] && map[row][col] <= 'Z') {
		doors[map[row][col] - 'A'].push_back( { row,col });
		return true;
	}
	return false;
}

bool isKey(int row, int col) {
	if ('a' <= map[row][col] && map[row][col] <= 'z') {
		keys[map[row][col] - 'a'] = 1;
		return true;
	}
	return false;
}

void print() {

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (visited[i][j])
				cout << '-' << " ";
			else
				cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------\n\n";

}


void process(int row, int col) {
	char cur = map[row][col];
	if (cur == '*') return;

	if (cur == '.') {
		q.push(make_pair(row, col));
		visited[row][col] = 1;
	}
	else if (cur == '$') {
		q.push(make_pair(row, col));
		visited[row][col] = 1;
		answer++;
	}
	else if (isDoor(row, col)) {
		if (keys[cur - 'A']) {
			q.push(make_pair(row, col));
			visited[row][col] = 1;
		}
	}
	else if (isKey(row, col)) {
		q.push(make_pair(row, col));
		visited[row][col] = 1;

		if (!doors[cur - 'a'].empty()) {
			for (auto pos : doors[cur - 'a']) {
				q.push(pos);
				visited[pos.first][pos.second] = 1;
			}			
		}
	}


//	print();
}

void solve() {
	
	init();

	// 벽면 따라서 처리 
	int dir = 0;
	pair<int, int> cur = { 0,0 };
	do {
		process(cur.first, cur.second);

		pair<int, int> next = make_pair(cur.first + dr[dir], cur.second + dc[dir]);
		if (!isInRange(next.first, next.second)) {
			dir++;
			next = make_pair(cur.first + dr[dir], cur.second + dc[dir]);
		}
		cur = next;

	} while (cur.first != 0 || cur.second != 0);

	//본격 시작~
	while(!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();	

		int nextCol, nextRow;
		for (int i = 0; i < 4; i++) {
			nextRow = cur.first + dr[i];
			nextCol = cur.second + dc[i];

			if (isInRange(nextRow, nextCol) && !visited[nextRow][nextCol]) {
				process(nextRow, nextCol);
			}
		}
	}

	cout << answer << "\n";
}

int main() {

	int testcase;
	cin >> testcase;


	while (testcase--) {
		solve();
	}

	return 0;
}