#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dp1[2][1000001];
int dp2[2][1000001];


int solution(vector<int> money) {
	int house = money.size();

	dp1[0][1] = money[0];
	for (int i = 2; i <= house; i++) {
		dp1[0][i] = max(dp1[0][i - 2], dp1[1][i - 1]) + money[i - 1]; //훔침
		dp1[1][i] = max(dp1[0][i - 1], dp1[1][i - 1]); //안훔치고 그냥넘어감

		dp2[0][i] = max(dp2[0][i - 2], dp2[1][i - 1]) + money[i - 1]; //훔침
		dp2[1][i] = max(dp2[0][i - 1], dp2[1][i - 1]); //안훔치고 그냥넘어감
	}

	int result1 = dp1[1][house]; //dp1 은 첫번째 집을 무조건 터는거라 막집은 절대 못턴다
	int result2 = max(dp2[0][house], dp2[1][house]);

	return max(result1, result2);
}
int main() {

	cout << solution({ 1, 2, 3, 1 }) << " " <<  4 << endl;
	cout << solution({ 1, 1, 4, 1, 4 })<< " "<<  8 << endl;
	cout << solution({ 1000, 0, 0, 1000, 0, 0, 1000, 0, 0, 1000 }) << " " << 3000 << endl;
	cout << solution({ 1000, 1, 0, 1, 2, 1000, 0 }) << " " << 2001 << endl;
	cout << solution({ 1000, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 1000 }) << " " << 2000 << endl;
	cout << solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }) << " " << 30 << endl;
	cout << solution({ 0, 0, 0, 0, 100, 0, 0, 100, 0, 0, 1, 1 }) << " " << 201 << endl;
	cout << solution({ 11, 0, 2, 5, 100, 100, 85, 1 }) << " " << 198 << endl;
	cout << solution({ 1, 2, 3 }) <<" " << 3 << endl;
	cout << solution({ 91, 90, 5, 7, 5, 7 }) << " " << 104 << endl;
	cout << solution({ 90, 0, 0, 95, 1, 1 }) << " " << 185 << endl;

	return 0;
}

