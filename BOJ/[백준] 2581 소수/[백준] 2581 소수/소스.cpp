#include <iostream>
#include <cmath>
using namespace std;

int prime[1001];

void findPrime(int n) {
	prime[0] = 1; // 1 �� �Ҽ��� �ƴϴ�.

	int num = int(sqrt(n));

	for (int i = 2; i <= num; i++) {
		if (prime[i - 1])
			continue;

		for (int j = 2; j*i <= n; j++) {
			prime[i*j - 1] = 1;
		}
	}
}


int main() {
	int N, M;
	cin >> N >> M;


	findPrime(M); //���� ū������ �����ӱ��ϱ�

	bool min = true;
	int sum = 0;
	int count = 0;
	int minVal = 0;

	for (int i = N; i <= M; i++) {
		if (prime[i - 1] == 0) {
			sum += i;
			if (min) {
				minVal = i;
				min = false;
			}
			count++;
		}
	}
		
	if (count == 0)
		cout << "-1\n";
	else
		cout << sum << "\n" << minVal << "\n";

}