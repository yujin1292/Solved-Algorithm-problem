#include <iostream>
using namespace std;

int const MAX = 1000001;
int mod = 1000000007;
int mem[MAX];

int  dp(int n) {

	if (n == 0)
		return 1;
	if (n == 1)
		return 2;
	if (n == 2)
		return 7;

	int result = 2 *dp(n - 1) + 3*dp(n-2);

	for (int i = 3; i <= n; i++) { // �� �κ��� �����Ը��������� 2���� dp
		result += 2 * dp(n - i);
		result %= mod;
	}

	mem[n] = result;
	return mem[n];
}


long long d[MAX][2];

int dp2(int n) {

	d[0][0] = 0;
	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 1;

	for (int i = 3; i <= n; i++) {
		d[i][1] = (d[i - 1][1] + d[i - 3][0]) % mod; // 2�����Ѱ� �����ִ����
		// 3��°�� ����� ���� ��갪�� ���ϸ� �ݺ��ؼ����Ѱ͸��ɵ�
		d[i][0] = (3 * d[i - 2][0] + 2 * d[i - 1][0] + 2 * d[i][1]) % mod; //��ȭ�Ŀ����Ѱ��
	}

	return d[n][0];

}



int main() {

	int n;
	cin >> n;

	cout << dp2(n);


}