#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

struct _pos {
	int x;
	int y;
} typedef pos;

vector<pos> empty_area;
vector<pos> virus;

int map[9][9];
int visited[9][9];

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1, -1, 0, 0 };

int answer = 0;

void solve(vector<pos> selected) {

	queue<pos> q;
	int map_copy[9][9];

	// init
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
			map_copy[i][j] = map[i][j];
		}
	}

	for (pos p : selected) {
		map_copy[p.x][p.y] = 1;
	}

	for (pos p : virus) {
		q.push(p);
	}


	while (!q.empty()) {

		pos cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			pos next;
			next.x = cur.x + dc[i];
			next.y = cur.y + dr[i];

			if (next.x < 0 || next.x >= N) continue;
			if (next.y < 0 || next.y >= M) continue;
			if (visited[next.x][next.y]) continue;
			if (map_copy[next.x][next.y] != 0) continue;

			q.push(next);
			map_copy[next.x][next.y] = 2; // virus
			visited[next.x][next.y] = 1;
		}
	}


	// count area
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map_copy[i][j] == 0) result++;
		}
	}


	if (answer < result) {
		answer = result;
	}
}

void select(int count, int idx, vector<pos> selected) {
	if (count == 3) {	
		solve(selected);
		return;
	}

	for (int i = idx; i < empty_area.size(); i++) {
		selected.push_back(empty_area[i]);
		select(count + 1, i + 1, selected);
		selected.pop_back();
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				pos area = pos();
				area.x = i;
				area.y = j;
				empty_area.push_back(area);
			}
			else if (map[i][j] == 2) {
				pos v = pos();
				v.x = i;
				v.y = j;
				virus.push_back(v);
			}
		}
	}

	vector<pos> s;

	select(0, 0, s);

	cout << answer <<  endl;
	return 0;
}