#include <iostream>
#include <algorithm>
#define MAX 300
using namespace std;

int N;
int arr[MAX];
int point[MAX][2];

int dp() {
	point[0][0] = arr[0];
	point[1][0] = max(point[0][0], point[0][1]) + arr[1];
	point[1][1] = arr[1];

	for (int i = 2; i < N; i++) {
		point[i][0] = point[i - 1][1] + arr[i];
		point[i][1] = max(point[i - 2][0], point[i - 2][1]) + arr[i];
	}

	return max(point[N - 1][0], point[N - 1][1]);
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << dp() << "\n";
	return 0;
}