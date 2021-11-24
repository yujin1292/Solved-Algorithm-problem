#include <iostream>
#define max 1001

using namespace std;

int map[max][max];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
	int n, find;
	int x, y, row, col;

	cin >> n >> find;
	row = col = x = y = n / 2;

	int dir = 0;
	int size = 1;
	int num = 1;

	map[row][col] = num;
	bool run = true;

	while (run) {

		for (int i = 0; i < size; i++) {
			row += dr[dir];
			col += dc[dir];
			map[row][col] = ++num;

			//if (row == 0 && col == 0) {
			//	run = false;
			//	break;
			//} 

			if (num == n * n) {
				run = false;
				break;
			}
		}
		dir++;
		dir %= 4;
		if (dir % 2 == 0) size++;
	}

	// 정답 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
			if (find == map[i][j]) {
				x = i + 1;
				y = j + 1;
			}
		}
		cout << endl;
	}
	cout << x << " " << y;

	return 0;
}