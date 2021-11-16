#include <iostream>
#define MAX 12000
using namespace std;

char star[MAX][MAX];

void makeStar(int x, int y, int hight) {

	if (hight == 3) {
		star[x][y] ='*';
		star[x + 1][y - 1] = star[x + 1][y + 1] = '*';
		for (int i = 0; i < 3; i++)
			star[x + 2][y - i] = star[x + 2][y + i] = '*';
		return;
	}
	int h = hight / 2;
	makeStar(x , y, h);
	makeStar(x +h , y - h, h);
	makeStar(x +h , y + h, h);
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n * 2; j++)
			star[i][j] = ' ';

	makeStar(0, n, n);

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n*2; j++) {
			cout << star[i][j];
		}
		cout << "\n";
	}

	return 0;
}