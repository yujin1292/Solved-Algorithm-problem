#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;

int map[MAX][MAX];
int visit[MAX][MAX];
int N, M;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };


bool outOfRange(pair<int, int> a) {
	int x = a.first;
	int y = a.second;

	if (1 <= x && x <= N) {
		if (1 <= y && y <= M)
			return false;
	}
	return true;

}

void solve() { // 1이 길이고 0 이 벽 
	queue<pair<int, int> > q;
	
	pair<int, int> cur,next;
	int len = 1;

	q.push(make_pair(1,1));
	visit[1][1] = 1;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			cur = q.front();
		//	cout <<"( "<<  cur.first << ", " << cur.second << ")  :" << len  <<"\n";
			
			if (cur.first == N && cur.second == M) {
				cout << len << endl;
				return;
			}


			for (int i = 0; i < 4; i++) {
				next.first = cur.first + dr[i];
				next.second = cur.second + dc[i];

				if (visit[next.first][next.second])
					continue;
				if (outOfRange(next))
					continue;

				if (map[next.first][next.second] == 0) //벽
					continue;

				visit[next.first][next.second] = 1;
				q.push(next);

			}

			q.pop();
			
		}
		len++;

	}

	cout << -1 << endl;
}


int main() {
	cin >> N >> M;
	string temp;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < M; j++)
			map[i+1][j+1] = temp[j]-'0';
	}

	solve();

	return 0;

}