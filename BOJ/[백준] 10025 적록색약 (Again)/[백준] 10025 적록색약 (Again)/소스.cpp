#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 101;

int dc[4] = { 1,-1, 0,0 };
int dr[4] = { 0,0,-1,1 };

int N;

char picture[MAX][MAX];
char picture_blind[MAX][MAX];

int visited_not_blind[MAX][MAX];
int visited_blind [MAX] [MAX] ;

void bfs(char(*pic)[MAX], int(*visited)[MAX], int row, int col) {
	queue<pair<int, int>> q;
	char color = pic[row][col];

	q.push(make_pair(row, col));
	visited[row][col] = 1;

	while (!q.empty()) {

		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = cur.first + dr[i];
			int next_col = cur.second + dc[i];

			if (0 > next_row || next_row >= N) continue;
			if (0 > next_col || next_col >= N) continue;
			if (visited[next_row][next_col]) continue;
			if (pic[next_row][next_col] != color) continue;
			
			q.push(make_pair(next_row, next_col));
			visited[next_row][next_col] = 1;
		}
	}
}

int main() {
	string line;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < N; j++) {
			if (line[j] == 'G') picture_blind[i][j] = 'R';
			else picture_blind[i][j] = line[j];
			picture[i][j] = line[j];
		}
	}

	// for blind
	int blind_area = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited_blind[i][j]) continue;
			blind_area++;
			bfs(picture_blind, visited_blind, i, j);
		}
	}


	// for not blind
	int area = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited_not_blind[i][j]) continue;
			area++;
			bfs(picture, visited_not_blind,i, j);
		}
	}

	cout << area << " " << blind_area << endl;
	return 0;
}