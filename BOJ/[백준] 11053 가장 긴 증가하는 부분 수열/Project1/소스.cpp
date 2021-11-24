#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>

#define endl "\n"

using namespace std;

int dp[10001][2];

int main() {
	int n, temp;
	cin >> n;
	int result = 1;
	int idx = 0;
	vector<int> v;


	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
		dp[i][0] = 1;
		dp[i][1] = -1;
	}
	// ±¸ÇÏ±â 
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (v[i] > v[j] && dp[i][0] <= dp[j][0]) {
				dp[i][0] = dp[j][0] + 1;
				dp[i][1] = j;
			}
		}
		if (result < dp[i][0]) {
			result = dp[i][0];
			idx = i;
		}
	}
	stack<int> answer;
	answer.push(v[idx]);
	while (dp[idx][1] != -1) {
		idx = dp[idx][1];
		answer.push(v[idx]);
	}
	cout << result << endl;
	while (!answer.empty()) {
		cout << answer.top() << " ";
		answer.pop();
	}

	return 0;
}