#include <iostream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;
const int MAX = 100001;
int N;

int board[MAX][3];

int main() {
	fastio;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];

	// ÃÖ´ñ°ª
	ll prevValue[3] = { board[0][0] , board[0][1] , board[0][2] };
	for (int i = 1; i < N; i++) {
		ll tempValue[3] = { 0, };
		for (int j = 0; j < 3; j++) {
			int prevCol = j + 1;
			ll maxValue = -1;
			for (int k = 0; k < 3; k++) {
				if (0 <= prevCol && prevCol < 3) {
					if (maxValue < prevValue[prevCol])
						maxValue = prevValue[prevCol];
				}
				prevCol--;
			}
			tempValue[j] = maxValue + board[i][j];
		}
		for (int j = 0; j < 3; j++)
			prevValue[j] = tempValue[j];
	}
	ll maxAnswer = 0;
	for (int i = 0; i < 3; i++) {
		if (prevValue[i] > maxAnswer) maxAnswer = prevValue[i];
	}


	// ÃÖ¼Ú°ª
	prevValue[0] = board[0][0];
	prevValue[1] = board[0][1];
	prevValue[2] = board[0][2];

	for (int i = 1; i < N; i++) {
		ll tempValue[3] = { 0, };
		for (int j = 0; j < 3; j++) {
			int prevCol = j + 1;

			ll minValue = 9*MAX;
			for (int k = 0; k < 3; k++) {
				if (0 <= prevCol && prevCol < 3) {
					if (minValue > prevValue[prevCol])
						minValue = prevValue[prevCol];
				}
				prevCol--;
			}
			tempValue[j] = minValue + board[i][j];
		}
		for (int j = 0; j < 3; j++)
			prevValue[j] = tempValue[j];
	}

	ll minAnswer = 9*MAX;
	for (int i = 0; i < 3; i++) {
		if (prevValue[i] < minAnswer) minAnswer = prevValue[i];
	}

	cout << maxAnswer << " " << minAnswer << "\n";
	return 0;
}