#include <iostream>

using namespace std;
int isIt(int num) {
	long result = num;
	long n = num;
	while ( n != 0) {
		result += (n % 10);
		n /= 10;
	}
	return result;
}

int main() {
	int num = 1;
	int N;
	cin >> N;
	while (true) {
		if (num > N) {
			cout << 0 << endl;
			return 0;
		}
		if (isIt(num) == N) {
			cout << num << endl;
			return 0;
		}
		num++;
	}

	return 0;
}