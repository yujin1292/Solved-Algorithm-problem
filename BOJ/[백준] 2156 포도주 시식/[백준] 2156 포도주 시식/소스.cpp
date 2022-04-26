#include <iostream>

using namespace std;

const int MAX = 10001;

int dp[MAX][3];
int glass[MAX];

const int DRINK_FIRST = 0; 
const int DRINK_SECOND = 1;
const int MAX_VALUE = 2; // ���� �������� �׳� .. �ϰ�;��

/*

dp[i][DRINK_FIRST] -> i ��° ���� ���� ���� ���Ű�� (���޾Ƽ� �ȸ�����)

dp[i][DRINK_SECOND] -> i ��° ���� ���� ����° ���Ű�� ( i-1 ���ð� ���޾Ƽ� )

dp[i][MAX_VALUE] -> i ��° �ܱ��� ���� �ִ� (i �� ���Ű�� / �ȸ��Ű�� ���� )

*/


int max(int a, int b, int c) {

	if (a < b) {
		if (b < c) return c;
		else return b;
	}
	else {
		if (a < c) return c;
		else return a;
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> glass[i];

		if (i == 1) {
			dp[i][DRINK_FIRST] = glass[i];
		}
		else {
			dp[i][DRINK_FIRST] = dp[i - 2][MAX_VALUE] + glass[i];
			dp[i][DRINK_SECOND] = dp[i - 1][0] + glass[i];
		}

		dp[i][MAX_VALUE] = max(dp[i - 1][MAX_VALUE], dp[i][DRINK_FIRST], dp[i][DRINK_SECOND]);
	}

	cout << dp[n][MAX_VALUE] << endl;

	return 0;
}