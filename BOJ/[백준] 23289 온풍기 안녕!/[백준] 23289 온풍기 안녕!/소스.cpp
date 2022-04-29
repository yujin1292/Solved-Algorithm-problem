#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;


int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

const int UP = 0;
const int RIGHT = 2;
const int DOWN = 4;
const int LEFT = 6;

int choco = 0;
int R, C, K, W;

int roomInfo[21][21];
int board[21][21];
bool wall[21 * 21][21 * 21];

vector<pair<int, int>> heaters;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
vector<vector<int>> heat;
vector<pair<int, int>> checkSpace;

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int getPosition(int x, int y) {
	return (x * C) + y;
}

bool inRange(int x, int y) {
	if (0 <= x && x < R) {
		if (0 <= y && y < C) return true;
	}
	return false;
}

bool goToStraight(int r, int c, int dir, int amount) {
	int nextR = r + dr[dir];
	int nextC = c + dc[dir];

	int curPos = getPosition(r, c);
	int nextPos = getPosition(nextR, nextC);

	if (!inRange(nextR, nextC)) return false;
	if (wall[curPos][nextPos]) return false;
	if (visited[nextR][nextC]) return false;


	visited[nextR][nextC] = true;
	q.push({ nextR,nextC });
	heat[nextR][nextC] += amount;

	return true;
}

bool goToDiagonal(pair<int, int> front, int i, int dir, int amount) {

	int frontPos = getPosition(front.first, front.second);

	int nextDirection = (dir + (i * 2) + 8) % 8;
	int tempR = front.first + dr[nextDirection];
	int tempC = front.second + dc[nextDirection];
	int tempPos = getPosition(tempR, tempC);

	nextDirection = (dir + i + 8) % 8;
	int turnR = front.first + dr[nextDirection];
	int turnC = front.second + dc[nextDirection];
	int turnPos = getPosition(turnR, turnC);


	// �߰� �������� ���� �ִ��� üũ 
	if (!inRange(tempR, tempC)) return false;
	if (wall[tempPos][frontPos]) return false;

	// ���������� �����ϴ� �밢 üũ
	if (!inRange(turnR, turnC)) return false;
	if (wall[turnPos][tempPos]) return false;
	if (visited[turnR][turnC]) return false;

	visited[turnR][turnC] = true;
	q.push({ turnR,turnC });
	heat[turnR][turnC] += amount;

	return true;
}

void initHeater() {
	heat = vector<vector<int>>(R, vector<int>(C, 0));

	for (pair<int, int> heater : heaters) {
		visited = vector<vector<bool>>(R, vector<bool>(C, false));
		q = queue<pair<int, int>>();
		int amount = 5;

		int dir = roomInfo[heater.first][heater.second];
		int r = heater.first + dr[dir];
		int c = heater.second + dc[dir];
		
		q.push({ r,c });
		visited[r][c] = true;
		heat[r][c] += amount--;

		for (; amount > 0; amount--) {
			int qsize = q.size();
			while (qsize--) {
				pair<int, int> front = q.front();
				q.pop();

				// ����
				goToStraight(front.first, front.second, dir, amount);

				// ������ : dir-2  dir+ 2 , �밢���� dir-1 dir+1
				for (int i = -1; i <= 1; i += 2) goToDiagonal(front, i, dir, amount);
			}
		}
	}
}

void turnOnHeater() {
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			board[i][j] += heat[i][j];
}

void adjustTemp() {
	vector<vector<int>> change = vector<vector<int>>( R, vector<int>( C, 0 ) );
	vector<vector<bool>> ballanced = vector<vector<bool> >( R * C + 1, vector<bool>( R * C + 1, false ) );
	
	// ��ȭ�� ���
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			int curPos = getPosition(r, c);

			for (int i = 0; i < 4; i++) {
				int dir = i * 2;
				int nextR = r + dr[dir];
				int nextC = c + dc[dir];
				int nextPos = getPosition(nextR, nextC);

				if (!inRange(nextR, nextC)) continue;
				if (wall[nextPos][curPos]) continue;
				if (ballanced[nextPos][curPos]) continue;

				ballanced[curPos][nextPos] = true;
				ballanced[nextPos][curPos] = true;

				// �µ� ���� 
				int amount = (abs(board[r][c] - board[nextR][nextC]) / 4);
				if (board[r][c] < board[nextR][nextC]) {
					change[r][c] += amount;
					change[nextR][nextC] -= amount;
				}
				else {
					change[r][c] -= amount;
					change[nextR][nextC] += amount;
				}
			}
		}
	}

	// �ѹ��� ��ȭ�ֱ�
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			board[i][j] += change[i][j];
		
}

void decreaseOuter() {
	for (int i = 0; i < R; i++) {
		if (board[i][0] > 0) board[i][0]--;
		if (board[i][C - 1] > 0) board[i][C - 1]--;
	}
	for (int i = 1; i < C - 1; i++) {
		if (board[0][i] > 0) board[0][i]--;
		if (board[R - 1][i] > 0) board[R - 1][i]--;
	}
}

bool checkTemp() {// ��� ĭ�� �µ��� K�̻�����
	for (pair<int, int> space : checkSpace) {
		if (board[space.first][space.second] < K)
			return false;
	}
	return true;
}

int main() {
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> roomInfo[i][j];
			if (roomInfo[i][j] == 1) {
				roomInfo[i][j] = RIGHT;
				heaters.push_back({ i,j });
			}
			else if (roomInfo[i][j] == 2) {
				roomInfo[i][j] = LEFT;
				heaters.push_back({ i,j });
			}
			else if (roomInfo[i][j] == 3) {
				roomInfo[i][j] = UP;
				heaters.push_back({ i,j });
			}
			else if (roomInfo[i][j] == 4) {
				roomInfo[i][j] = DOWN;
				heaters.push_back({ i,j });
			}
			else if (roomInfo[i][j] == 5) {
				roomInfo[i][j] = -2;
				checkSpace.push_back({ i,j });
			}
			else {
				roomInfo[i][j] = -1;
			}
		}
	}

	cin >> W;
	for (int i = 0; i < W; i++) {
		int x, y, t;
		cin >> x >> y >> t;

		int to = getPosition(--x, --y);
		int from = (t == 0) ?  getPosition(x - 1, y) : getPosition(x, y + 1);
		
		wall[to][from] = true;
		wall[from][to] = true;
	}

	initHeater();

	while (true) {
		// ��ǳ�� �ٶ� �ѹ� ����
		turnOnHeater();

		// �µ� ���� 
		adjustTemp();

		// �ٱ� �µ� 1 ����
		decreaseOuter();

		// ���ݸ� �԰� Ȯ��
		if (++choco > 100) break;

		// �����ϱ���� ���ĭ ����
		if (checkTemp()) break;
	}

	//print();
	cout << choco << "\n";
	return 0;
}