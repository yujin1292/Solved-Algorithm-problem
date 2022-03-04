#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long 
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

ll M, N, L;
vector<ll> guns;

bool could_hunted(ll start_x, ll end_x) {
	ll start = 0;
	ll end = M - 1;
	ll mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (start_x <= guns[mid] && guns[mid] <= end_x) {
			return true;
		}
		else {
			if (guns[mid] < start_x) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
	}

	return false;
}

int main() {

	int answer = 0;
	fastio;

	cin >> M >> N >> L;

	for (ll i = 0; i < M; i++) {
		ll x;
		cin >> x;
		guns.push_back(x);
	}

	sort(guns.begin(), guns.end());

	for (ll i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;

		if (y > L) continue; // 절대 공격못함

		// 사격당할수 있는 위치 선정
		ll start_x = x - (L - y) < 0 ? 0 : x - (L - y);
		ll end_x = x + (L - y);

		if (could_hunted(start_x, end_x)) {
			answer++;
		}
	}

	cout << answer;
	return 0;
}