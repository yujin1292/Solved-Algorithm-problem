#include <iostream>

using namespace std;
int minimum(int a, int b) {
	return a < b ? a : b;
}

int bino(int n, int k) { // 재귀호출 이용하기
	if (k == 0 || n == k) {
		return 1;
	}
	else {
		return bino(n - 1, k - 1) + bino(n - 1, k);
	}
}


// 메모이제이션을 이용한 이항 계수의 계산
int const MAX = 10000;
int B[MAX][MAX];

int bino1(int n, int r) {
	if (r == 0 || n == r)
		return;

	if (B[n][r] == 0)
		return B[n][r];
	B[n][r] = bino1(n - 1, r - 1) + bino(n - 1, r);
	
	return B[n][r];
}


int bino2(int n, int k) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= minimum(i, k); j++) {
			if (j = 0 || j == i)
				B[i][j] = 1;
			else
				B[i][j] = B[i - 1][j - 1] + B[i - 1][j];

		}
	}
	return B[n][k];
}


int main() {


	return 0;
}