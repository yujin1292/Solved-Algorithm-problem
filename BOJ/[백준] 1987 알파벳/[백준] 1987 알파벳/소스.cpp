#include <iostream>
#include <vector>
#include <string>
#define MAX 20
using namespace std;

int visit[MAX][MAX];
int map[MAX][MAX];
int alpha[26];

int R, C;
int result = 0;
int dc[] = { 1, 0, 0, -1 };
int dr[] = { 0,1,-1, 0 };
bool inRange(pair<int, int> p) {
	if (0 <= p.first && p.first < R)
		if (0 <= p.second && p.second < C)
			return true;
	return false;
}

void dfs(pair<int, int> pos, int distance) {

	//방문 정보 업데이트
	char c = map[pos.first][pos.second];
	visit[pos.first][pos.second] = 1;
	alpha[c - 'A'] = 1;

	// result 업데이트
	if (result < distance)
		result = distance;

	pair<int, int> next;
	char next_c;

	for (int i = 0; i < 4; i++) {
		next = make_pair(pos.first + dr[i], pos.second + dc[i]);
		if (!inRange(next)) //범위체크
			continue;
		if (visit[next.first][next.second]) //방문한곳인지 체크
			continue;
		next_c = map[next.first][next.second];
		if (alpha[next_c - 'A']) //밟았던 알파벳인지 체크
			continue;

		dfs(next, distance + 1);
		//원상복구
		visit[next.first][next.second] = 0;
		alpha[next_c - 'A'] = 0;
	}
	
}
int main() {
	cin >> R >> C;
	string temp;

	for (int i = 0; i < R; i++) {
		cin >> temp;
		for (int j = 0; j < C; j++)
			map[i][j] = temp[j];
	}	
	dfs(make_pair(0,0), 1);

	cout << result;
	return 0;
}