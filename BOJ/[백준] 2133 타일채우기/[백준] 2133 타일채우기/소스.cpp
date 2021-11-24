#include <iostream>
using namespace std;

int const MAX = 1001;

int mem[MAX];

int  dp(int n) {

	if (n == 0)
		return 1;
	if (n == 1)
		return 0;
	if (n == 2)
		return 3;

	int result = 3 * dp( n - 2);

	for (int i = 3; i <= n; i++) {
		if (i % 2 == 0)
			result += 2 * dp(n - i);
	}

	mem[n] = result;
	return mem[n];
}



int main() {

	int n;
	cin >> n;

	cout << dp(n);


}