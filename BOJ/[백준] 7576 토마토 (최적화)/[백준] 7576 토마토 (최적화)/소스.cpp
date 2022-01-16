#include <iostream>
#include <queue>

using namespace std;

int const MAX = 1001;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int arr[MAX][MAX];
int M, N;
int date;
int unripped;
queue <pair<int, int> > ripped;

void bfs() {
	date = -1;
	while (!ripped.empty()) {
		int qsize = ripped.size();
		while (qsize--) {
			int a = ripped.front().first;
			int b = ripped.front().second;
			ripped.pop();


			for (int i = 0; i < 4; i++) {
				int x = a + dx[i]; // 다음좌표
				int y = b + dy[i];

				//범위 체크
				if (x < 0 || x >= N || y < 0 || y >= M)
					continue;

				if (arr[x][y] == 0) {
					arr[x][y] = 1;
					ripped.push(make_pair(x, y));
					unripped--;
				}
			}
		}
		date++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				ripped.push(make_pair(i, j));
			}
			else if( arr[i][j] == 0) {
				unripped++;
			}
		}
	}

	bfs();

	if (unripped != 0) cout << -1;
	else cout << date;

	return 0;
}