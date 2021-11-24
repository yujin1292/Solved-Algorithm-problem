//시간초과 코드
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX 500
using namespace std;

int MOD = 20170805;
int answer , M ,N;
int visit[MAX][MAX];
vector<vector<int>> city;
vector<int> dr = { 0, 1};
vector<int> dc = { 1, 0 };

bool inRange(pair<int, int> a) {
	if (0 <= a.first && a.first < M)
		if (0 <= a.second && a.second < N)
			return true;
	return false;
}
void dfs(pair<int, int> cur , int dir) {
	
	visit[cur.first][cur.second] = 1;
	
	if (cur.first == M - 1 && cur.second == N - 1) {
		answer++;
		answer %= MOD;
		return;
	}

	pair<int, int> next;
	if (city[cur.first][cur.second] == 2) { //방향전환 불가능
		next = { cur.first + dr[dir] , cur.second + dc[dir] };

		if (!inRange(next))	return;
		if (visit[next.first][next.second])	return;
		if (city[next.first][next.second] == 1) return;

		dfs(next, dir);
		visit[next.first][next.second] = 0;
		return;
	}
	else { // 0 이겠쥬 1은 아에 안들어올태니깐
		for (int i = 0; i < 2; i++) {
			next = { cur.first + dr[i] , cur.second + dc[i] };

			if (!inRange(next)) continue;
			if (visit[next.first][next.second])	continue;
			if (city[next.first][next.second] == 1)	continue;

			dfs(next, i);
			visit[next.first][next.second] = 0;
		}
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	answer = 0;
	M = m;
	N = n;
	city = city_map;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;

	dfs({ 0,0 }, -1);
	return answer;
}



int main() {

	cout << solution(3, 3, { {0, 0, 0},{0, 0, 0},{0, 0, 0} })<< endl;

}

