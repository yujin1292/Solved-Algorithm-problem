#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string C[103][103];

string sum(string num1, string num2) {

	long long sum = 0;
	string result = "";
	//1�� �ڸ����� ���ϱ� �����Ѵ�

	while (!num1.empty() || !num2.empty() || sum){
		if (!num1.empty()){
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()){
			sum += num2.back() - '0';
			num2.pop_back();
		}
		//�ٽ� string ���·� ����� push_back
		result.push_back((sum % 10) + '0');
		sum /= 10;

	}

	//1�� �ڸ����� result�� �־����Ƿ� ����������Ѵ�
	reverse(result.begin(), result.end());
	return result;
}

int main() {

	int N, M;
	cin >> N >> M;


	for (int n = 1; n <= N + 1; n++) {
		for (int m = 1; m <= N + 1; m++) {
			if (n == 1 && m == 1) {
				C[1][1] = "1";
				continue;
			}

			C[n][m] = sum(C[n - 1][m - 1], C[n - 1][m]);

			if (n == N + 1 && m == M + 1) {
				cout << C[n][m];
				return 0;
			}
		}
	}

	return 0;
}