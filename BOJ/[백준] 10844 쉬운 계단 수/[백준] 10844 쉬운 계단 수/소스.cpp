#include <iostream>
#define ll long long 
using namespace std;


ll dp[100][10];
int mod = 1000000000;

int main() {
	int n;
	cin >> n;

	for (int digit = 0; digit <= 9; digit++) {
		dp[0][digit] = 1;
	}
	dp[0][0] = 0;

	for (int i = 1; i < n; i++) {
		for (int digit = 0; digit <= 9; digit++) {
			if (digit == 9) {
				dp[i][digit] = dp[i - 1][digit - 1];
			}
			else if (digit == 0) {
				dp[i][digit] = dp[i - 1][digit + 1];
			}
			else {
				dp[i][digit] = dp[i - 1][digit - 1] + dp[i - 1][digit + 1];
			}
			dp[i][digit] %= mod;
		}
	}


	ll answer = 0L;
	for (int digit = 0; digit <= 9; digit++) {
		answer += dp[n - 1][digit];
		answer %= mod;
	}

	cout << answer;

	return 0;
}