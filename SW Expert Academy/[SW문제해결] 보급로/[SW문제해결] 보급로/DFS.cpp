// DFS�� �̿�������쿡�� �ʹ����� ����Ǽ��� ���ܳ��⶧����
// ��Ʈ��ŷ�� �̿��ص� �ð��ʰ� BFS�� �̿��ؾ���

#include <iostream>
#include <string>

#define MAX 100

using namespace std;

int visit[MAX][MAX];
int map[MAX][MAX];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int N;
int value;

void init() { //visit �ʱ�ȭ
	value = 999999999;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;
	}
}
bool isVisited(int x, int y) {
	if (visit[x][y] == 0)
		return false;
	return true;
}
bool isValid(int x, int y) {
	if (0 <= x && x < N)
		if (0 <= y && y < N)
			return true;
	
	return false;
}
void solve(int x, int y, int time) {
	visit[x][y] = 1;
	if (x == N-1 && y == N-1) { //G���� ����
		if (time < value) {
			value = time; //min�� update;
			cout << "min : " << time << endl;
		}
		return;
	}

	if (time >= value)
		return;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (!isValid(nextX, nextY))
			continue;
		if (isVisited(nextX, nextY))
			continue;

		solve(nextX, nextY, time + map[nextX][nextY]);
		visit[nextX][nextY] = 0; 
	}

}

int main() {
	//�ð��ʰ�

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	string temp;

	cin >> testcase;
	for (int test = 0; test < testcase; test++) {
		init();

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			for (int j = 0; j < N; j++) {
				map[i][j] = temp[j] - '0';
			}
		}

		solve(0, 0, 0);
		cout << "#" << test + 1 << " " << value << "\n";
	}

}