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
		dp[i] = temp;
	}
	// ±¸ÇÏ±â 
	for (int i = 0; i < n; i++) {


		for (int j = i - 1; j >= 0; j--) {
			if (v[i] > v[j])
				if( dp[j] + v[i] > dp[i]) dp[i] = dp[j] + v[i];
		}
		if (result < dp[i]) result = dp[i];
	}
	cout << result;
	return 0;
}