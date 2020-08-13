#include <iostream>
using namespace std;

int numX[1001];
int numY[1001];

int main() {
	int pos[6];

	int inputX, inputY;
	for (int i = 0; i < 3; i++) {
		cin >> inputX >> inputY;
		numX[inputX]++;
		numY[inputY]++;
		pos[i] = inputX;
		pos[5 - i] = inputY;
	}
	int xx, yy;
	yy =xx= 0;
	for (int i = 0; i < 3; i++) {
		if (numX[pos[i]] == 1)
			xx = pos[i];
	}

	for (int i = 3; i < 6; i++) {
		if (numY[pos[i]] == 1)
			yy = pos[i];
	}

	cout << xx << " " << yy << "\n";
	return 0;
}