#include <iostream>
#include <vector>
#include <math.h>
#include <memory.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 4000001
using namespace std;

bool isPrime[MAX];
int N;

void eratosthenes(int n) { //n 까지의 소수 체크 
	memset(isPrime, 1, sizeof(isPrime)); //모두 true로 초기화

	isPrime[0] = isPrime[1] = false;

	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; i++) {
		if (isPrime[i]) // i*i 이하의 i배수는 이미 false 상태
			for (int j = i * i; j <= n; j += i)
				isPrime[j] = false;
	}
}


int nextPrime(int n) {
	for (int i = n + 1; i <= N; i++)
		if (isPrime[i]) return i;
	return N+1;
}

int main() {
	fastio;

	cin >> N;

	int start = -1, end = -1, result = 0;
	int sum = 0;
	
	eratosthenes(N);

	while (start <= end && end <= N) {
		if (N < sum) { // 줄여야됨 
			start = nextPrime(start);
			sum -= start;
		}
		else if (N > sum) { // 더 더해야한다
			end = nextPrime(end);
			sum += end;
		}
		else {
			result++;
			end = nextPrime(end);
			sum += end;
		}
	}
	cout << result << endl;
	return 0;
}