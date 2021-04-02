#include <iostream>

using namespace std;

int P[101];
int T, N;

int pado(int n) {

	if (P[n] == 0) {
		P[n] = pado(n - 1) + pado(n - 5);
		return P[n];
	}

	else
		return P[n];
}

int main() {

	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;
	P[6] = 3;
	P[7] = 4;
	P[8] = 5;
	P[9] = 7; // 4+8
	P[10] = 9; // 5+9


	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;

		cout << pado(N)<<"\n";

	}

	return 0;
}