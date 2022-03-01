#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> lines;
int dp[1001];

int lis() {
	int result = 1;

	for (int i = 0; i < lines.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (lines[i] > lines[j] && dp[i] <= dp[j])
				dp[i] = dp[j] + 1;
		}
		if (result < dp[i]) result = dp[i];
	}
	return result;
}

int main() {
	int N;
	cin >> N;
	
	map<int, int> m;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		m[a] = b;
	}

	int size = 0;
	for (auto m : m) {
		lines.push_back(m.second);		
		dp[size++] = 1;
	}


	cout << lines.size() - lis() << endl;

	return 0;
}