#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 51

using namespace std;

int map[MAX][MAX];
int visit[MAX][MAX];
int M, N, K ;

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j])
				cout << "o ";
			else
				cout << ". ";
		}
		cout << endl;
	}
}

bool inRange(int x, int y) {
	if (0 <= x && x < N) 
		if (0 <= y && y < M) 
			return true;	
	return false;
}
void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visit[i][j] = map[i][j] = 0;
}
void check(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x,y });
	visit[x][y] = 1;
	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
	
		for (int i = 0; i < 4; i++) {
			
			
			if (!inRange(curX + dc[i], curY + dr[i]))
				continue;
			if (map[curX + dc[i]][curY + dr[i]] == 0)
				continue;
			if (visit[curX + dc[i]][curY + dr[i]])
				continue;
			
			visit[curX + dc[i]][curY + dr[i]] = 1;
			q.push({ curX + dc[i], curY + dr[i] });	

		}

	}

}
int solve() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 || visit[i][j])
				continue;
			check(i, j);
			count++;
		}
	}
	return count;
}


int main() {
	int testcase , x,y;	
	cin >> testcase;
	N = M = 0;

	for (int t = 0; t < testcase; t++) {
		cin >> M >> N >> K;
		init();
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		//print();
		cout<< solve() <<"\n";
	}
	return 0;
}