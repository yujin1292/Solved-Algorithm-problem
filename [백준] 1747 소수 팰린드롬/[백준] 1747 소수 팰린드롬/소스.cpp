#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

bool checkIsPrime(int num) {
	if (num <= 1) return false;
	if (num == 2) return true;
	if (num % 2 == 0) return false;

	for (int i = 3; i <= sqrt(num); i += 2) {
		if (num % i == 0) return false;
	}

	return true;
}

bool isPallendrom(int n) {
	string num = to_string(n);
	for (int i = 0; i < num.size() /2; i++) {
		if (num[i] != num[num.size() - 1 - i]) return false;
	}
	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	while (true) {
		if (checkIsPrime(N) && isPallendrom(N)) {
			cout << N;
			break;
		}
		N++;
	}

	return 0;
}
