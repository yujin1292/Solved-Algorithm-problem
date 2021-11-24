#include <iostream>
using namespace std;

int const MAX = 1001;

int mem[MAX];

int  dp(int n) {

	if (n == 1)
		return  1;
	if (n == 2)
		return 3;

	if (mem[n] != 0) return mem[n];

	mem[n] = (dp(n - 1) + dp(n - 2)*2) % 10007;
	return mem[n];
}



int main() {

	int n;
	cin >> n;

	cout << dp(n);


}