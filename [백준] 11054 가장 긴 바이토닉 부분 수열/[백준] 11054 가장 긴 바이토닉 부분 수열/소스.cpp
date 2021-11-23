#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int dp[1001]; // �����ϴ� �κм���
int dp2[1001]; // �����ϴ� �κм���

int main() {
	int n, temp;
	cin >> n;
	vector<int> v;


	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
		dp[i] = dp2[i] = 1;
	}

	// ���ϱ� 
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (v[i] > v[j] && dp[i] <= dp[j])
				dp[i] = dp[j] + 1;
		}
	}

	for (int i = n-1; i >=0 ; i--) {
		for (int j = i + 1 ; j < n; j++) {
			if (v[i] > v[j] && dp2[i] <= dp2[j])
				dp2[i] = dp2[j] + 1;
		}
	}
	
	int result = 1;
	for (int i = 0; i < n; i++) {
		if (result < dp[i] + dp2[i]) result = dp[i] + dp2[i];
	}

	cout << result-1;
	return 0;
}