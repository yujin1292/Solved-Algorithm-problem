#include <iostream>
using namespace std;

void multi(long long m1[][2], long long m2[][2]) {
	long long tmp[2][2];
	long long temp;

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			temp = 0;
			for (int k = 0; k < 2; ++k) {
				temp += (m1[i][k] * m2[k][j]);
			}
			tmp[i][j] = temp % 1000000007;
		}
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			m1[i][j] = tmp[i][j];
		}
	}

	return;
}

int main() {
	long long mat[2][2] = { 1, 1, 1, 0 };
	long long res[2][2] = { 1, 0, 0, 1 };
	long long n;

	cin >> n;
	while (n > 0) {
		if (n % 2 == 1) {
			multi(res, mat);
		}

		n /= 2;
		multi(mat, mat);
	}

	cout << res[1][0];
}