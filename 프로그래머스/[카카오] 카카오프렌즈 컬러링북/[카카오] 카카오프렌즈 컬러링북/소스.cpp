#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visit[100][100];
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1, 0,0 };

void init(int m, int n) {
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++)
			visit[i][j] = 0;
	
}
bool inRange(pair<int, int> next, int m, int n) {
	int i = next.first;
	int j = next.second;
	if (0 <= i && i < m)
		if (0 <= j && j < n)
			return true;
	return false;
}
int bfs(int startX, int startY , int m, int n , vector<vector<int>> picture) {
	int count = 0;
	queue<pair<int, int> > q;

	q.push(make_pair(startX, startY));
	visit[startX][startY] = 1;
	count++;
	int color = picture[startX][startY];

	while (!q.empty()) {
		pair<int, int> front, next;

		front = q.front();
		for (int i = 0; i < 4; i++) {
			next.first = front.first + dr[i];
			next.second = front.second + dc[i];

			if (!inRange(next,m,n))
				continue;
			if (visit[next.first][next.second] == 1)
				continue;
			if (picture[next.first][next.second] != color)
				continue;

			q.push(next);
			visit[next.first][next.second] = 1;
			count++;
		}

		q.pop();
	}


	return count;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	init(m, n);
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j])
				continue;
			if (picture[i][j] == 0)
				continue;

			int temp = bfs(i, j , m,n , picture);
			number_of_area++;
			if (max_size_of_one_area < temp)
				max_size_of_one_area = temp;
		}
	}



	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}