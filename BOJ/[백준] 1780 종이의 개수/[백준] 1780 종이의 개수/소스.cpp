#include <iostream>
#define MAX 2200
using namespace std;

int N, under, zero, one;
int paper[MAX][MAX];

void solve(int x, int y, int len) {
	int color = paper[x][y];

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (color != paper[x + i][y + j]) {
				//다를경우
				for (int ii = 0; ii < 3; ii++) 
					for (int jj = 0; jj < 3; jj++) 
						solve(x + (len / 3)*ii, y + (len / 3)*jj, len / 3);								
				return;
				
			}
		}
	}
	if (color == 0)
		zero++;
	else if (color == 1)
		one++;
	else
		under++;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];
	

	solve(0, 0, N);

	cout << under << "\n";
	cout << zero << "\n";
	cout << one << "\n";


	return 0;
}