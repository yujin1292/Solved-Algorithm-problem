#include <iostream>
#define MAX 1001

using namespace std;

int m_min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int dp[MAX][3];
int cost[MAX][3];
int N;




void RGB_distance(int N) { //³ª¿øÈñ ÄÚµå 
	int arr[3];
	int min;
	int dp[3];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[0] >> arr[1] >> arr[2];
		int temp[3];

		temp[0] = dp[0];
		temp[1] = dp[1];
		temp[2] = dp[2];

		dp[0] = m_min(temp[1], temp[2]) + arr[0];
		dp[1] = m_min(temp[0], temp[2]) + arr[1];
		dp[2] = m_min(temp[0], temp[1]) + arr[2];
	}
	min = m_min(m_min(dp[0], dp[1]), dp[2]);
	cout << min;
}



int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	
	for (int i = 1; i <= N; i++) {
		dp[i][0] = m_min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = m_min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = m_min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	int m = MAX*N;
	for (int i = 0; i < 3; i++) {
		if (m > dp[N][i])
			m = dp[N][i];
	}
	cout << m << endl;

	return 0;
}