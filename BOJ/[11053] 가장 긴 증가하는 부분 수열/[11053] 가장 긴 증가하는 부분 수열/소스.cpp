#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int dp[1001];

int main() {
	int n, temp;
	cin >> n;
	int result = 1;
	vector<int> v;


	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
		dp[i] = 1;
	}
	// ±¸ÇÏ±â 
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (v[i] > v[j] && dp[i] <= dp[j]) 
				dp[i] = dp[j] + 1;
		}
		if (result < dp[i]) result = dp[i];
	}
	cout << result;
	return 0;
}