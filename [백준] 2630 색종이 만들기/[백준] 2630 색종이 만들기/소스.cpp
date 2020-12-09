#include <iostream>
#define MAX 128
using namespace std;

int paper[MAX][MAX];
int N,A,B;
void check(int len, int x, int y) {
	int color = paper[x][y];
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (i == x && j == y)
				continue;
			if (paper[x + i][y + j] != color) {
				check(len / 2, x, y);
				check(len / 2, x +len/2, y);
				check(len / 2, x, y + len / 2);
				check(len / 2, x + len / 2, y + len / 2);
				return;
			}
		}
	}
	if (color) B++;
	else A++;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	check(N, 0, 0);
	cout << A << "\n" << B << "\n";
	return 0;
}