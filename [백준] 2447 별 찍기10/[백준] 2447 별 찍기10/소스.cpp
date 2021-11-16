#include <iostream>
#define MAX 6562 // 3^8 + 1

using namespace std;

int N;
char star[MAX][MAX];

void fillWithBlank(int x, int y, int len) {
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			star[x + i][y + j] = ' ';
}

void makeStar(int x, int y, int len) {
	if (len == 3) {
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) 
					star[x + i][y + j] = ' ';
				else 
					star[x + i][y + j] = '*';
			}
		}

		return;
	}

	int gap = len / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			if (i == 1 && j == 1) {
				fillWithBlank(x + gap * i, y + gap * j, gap);
			}
			else {
				makeStar(x + gap * i, y + gap * j, gap);
			}

		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	makeStar(0,0,N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << star[i][j];
		cout << "\n";

	}

	return 0;
}