#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_LEN = 100001;

int dp[MAX_LEN];
int arr[MAX_LEN];

int main() {
	int n;
	cin >> n;
	int answer = -10001;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (i == 0) dp[i] = arr[i];
		else dp[i] = max(dp[i - 1] + arr[i], arr[i]);

		if (answer < dp[i]) answer = dp[i];
	}

	cout << answer << endl;
	return 0;
}