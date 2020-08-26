#include <iostream>

using namespace std;

int const MAX = 10000;
int N;
int coin[] = { 1, 3, 6 };
int memo[MAX];

int main() {

	cin >> N;
	int min;
	for (int n = 1; n <= N; n++) {
		min = MAX;
		for (int i = 0; i < 3; i++) {
			if (n >= coin[i]) {
				if (memo[n - coin[i]] < min)
					min = memo[n - coin[i]];

			}
		}
		memo[n] = min + 1;

	}
	cout << memo[N] << endl;


	return 0;
}