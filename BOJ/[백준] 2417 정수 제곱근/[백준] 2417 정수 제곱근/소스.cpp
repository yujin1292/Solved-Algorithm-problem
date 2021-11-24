#include <iostream>
#include <cmath>
#define ll unsigned long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	ll low = 0;
	ll high = sqrt(9223372036854776000) + 1; //2ÀÇ 63 Á¦°ö
	ll answer = 1;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	while (low <= high) {
		ll mid = (low + high) / 2;

//		cout << mid << ' ' << low << ' ' << high << '\n';

		ll MID = mid * mid;
		if (MID < n) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
			answer = mid;
		}
	}

	cout << answer;
	return 0;
}