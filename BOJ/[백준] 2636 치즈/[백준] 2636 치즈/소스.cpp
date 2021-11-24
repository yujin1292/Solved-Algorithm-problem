#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 101

using namespace std;

int N, M;
int map[MAX][MAX];
int dc[4] = { 0,0,1,-1 };
int dr[4] = { 1,-1, 0,0 };

int ans;

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == -1) cout << "- ";
			else cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------" << endl;
}

void checkOutAir(int col, int row) {
	queue<pair<int, int> > q;

	q.push(make_pair(row, col));
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextRow = front.first + dr[i];
			int nextCol = front.second + dc[i];

			if (nextRow < 0 || N <= nextRow) continue;
			if (nextCol < 0 || M <= nextCol) continue;

			if (map[nextRow][nextCol] > 0) {
				map[nextRow][nextCol]++;
				continue;
			}

			if (map[nextRow][nextCol] == 0) {
				map[nextRow][nextCol] = -1;
				q.push(make_pair(nextRow, nextCol));
			}
		}
	}
}

int isAllMelted() { // 남아있는 치즈 개수 반환 하면서 초기화
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) count++;
			else map[i][j] = 0;
		}
	}
	if (count != 0) ans = count;
	return count;
}

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int time = 0;
	while (isAllMelted() != 0) {
		time++;
		checkOutAir(0, 0);
		//print();
	}
	cout << time <<"\n"<< ans << endl;
	return 0;
}