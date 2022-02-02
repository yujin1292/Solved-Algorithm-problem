#include <iostream>
#include <string>
#include <algorithm>

#define ll long long
using namespace std;

const int MOD = 1000000;
string code = "";
ll dp[5001];


ll decode(int start) {
	// 메모이제이션
	if (dp[start] != -1) return dp[start];

	int len = code.size() - start;

	if (len <= 0) return 0;
	else if (code[start] == '0') return 0;
	else if (len == 1) return 1;

	int top = (code[start] - '0') * 10 + (code[start + 1] - '0');

	if (top <= 26) {
		dp[start] = (decode(start + 1) + decode(start + 2)) % MOD;
		if (len == 2) dp[start] = (dp[start] + 1) % MOD;
		return dp[start];
	}
	else {
		dp[start] = decode(start + 1) % MOD;
		return dp[start];
	}
}

int main() {

	cin >> code;

	fill(dp, dp + code.size(), -1);

	cout << decode(0);

	return 0;
}