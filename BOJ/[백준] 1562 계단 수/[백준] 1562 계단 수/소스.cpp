#include <iostream>
#define ll long long 
using namespace std;


const int SIZE = 1 << 10;
const int ALL_SELECTED = SIZE - 1;
const int MOD = 1000000000;

ll dp[100][10][SIZE];

/*

visited 는 비트마스크를 이용하여 표현하였습니다~


2진수의 각 자리수를 사용된 숫자라고 봐주시면됩니다
ex )
  visited : 0 1 0 0 0 0 0 1 1 1
   -> 0, 1, 2, 8  숫자를 사용했음!!


dp[ len ][ digit ][ visited ] 
= len 길이의 digit으로 끝나고 visited 에 체크되어있는 숫자를 가진  계단수

*/



int main() {

	int n;
	cin >> n;

	for (int digit = 1; digit <= 9; digit++) {
		dp[0][digit][1 << digit] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int digit = 0; digit <= 9; digit++) {
			int mask = 1 << digit;

			for (int visited = 0; visited <= ALL_SELECTED; visited++) {
				if (digit == 0) {
					dp[i][digit][visited | mask] += dp[i - 1][digit + 1][visited];
				}
				else if (digit == 9) {
					dp[i][digit][visited | mask] += dp[i - 1][digit - 1][visited];
				}
				else {
					dp[i][digit][visited | mask] += (dp[i - 1][digit - 1][visited] + dp[i - 1][digit + 1][visited]);
				}

				dp[i][digit][visited | mask] %= MOD;
			}
		}
	}


	// 정답 출력
	ll answer = 0L;
	for (int digit = 0; digit <= 9; digit++) {
		answer += dp[n - 1][digit][ALL_SELECTED];
		answer %= MOD;
	}
	cout << answer;

	return 0;
}