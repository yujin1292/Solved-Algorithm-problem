#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dc[4] = { 0,0,1,-1 };
int dr[4] = { 1,-1, 0,0 };

const int BLANK = 0;
const int SHARK = 9;
int n;
int map[21][21];


int curRow, curCol;
int sharkSize = 2;
int eaten = 0;


class Fish {
public:
	int row;
	int col;
	int distance;

	Fish(int r, int c, int d) {
		row = r;
		col = c;
		distance = d;
	}

	bool operator< (Fish f){
		if (distance == f.distance) {
			if (row == f.row) {
				return col < f.col;
			}
			return row < f.row;
		}
		return distance < f.distance;
	}
};

vector<Fish> getTargetFish() {
	vector<Fish> target;

	vector<vector<int>> visited( n, vector<int>(n, 0) ); // n * n 리스트 생성
	queue<pair<int,int>> q;

	q.push(make_pair(curRow, curCol));
	visited[curRow][curCol] = 1;
	
	int dist = 1;
	while (!q.empty()) {
		
		int qsize = q.size();
		while (qsize--) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();


			for (int i = 0; i < 4; i++) {
				int nextRow = r + dr[i];
				int nextCol = c + dc[i];

				if (nextRow < 0 || nextRow >= n) continue;
				if (nextCol < 0 || nextCol >= n) continue;
				if (visited[nextRow][nextCol]) continue;

				if (map[nextRow][nextCol] > sharkSize) continue;
				else if ( 0 < map[nextRow][nextCol] && map[nextRow][nextCol] < sharkSize) {
					target.push_back(Fish(nextRow, nextCol, dist));
				}

				q.push(make_pair(nextRow, nextCol));
				visited[nextRow][nextCol] = 1;
			}
		}
		dist++;
	}

	return target;
}

void eatFish(Fish f) {
	map[curRow][curCol] = 0;
	curRow = f.row;
	curCol = f.col;

	eaten++;
	map[f.row][f.col] = 9;

	if (eaten == sharkSize) {
		eaten = 0;
		sharkSize++;
	}
}

int main() {

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == SHARK) {
				curRow = i;
				curCol = j;
			}
		}
	}


	int time = 0;
	while (true) {

		// 먹을 수 있는 물고기 리스트 받음 
		auto list = getTargetFish();

		// 먹을수 없다면 break
		if (list.empty()) break;
		
		sort(list.begin(), list.end());
		eatFish(list.front());
		time += list.front().distance;
	}

	cout << time;
	return 0;
}