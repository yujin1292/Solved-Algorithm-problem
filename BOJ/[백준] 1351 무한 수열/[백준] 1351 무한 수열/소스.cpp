#include <iostream>
#include <algorithm>
#include <map>

#define ll long long 

using namespace std;

map<ll, ll> m;
ll P, Q;

ll solve(ll i) {
	if (i == 0) return 1;

	if (m.count(i)>0) return m[i];
	return m[i] = solve(i / P) + solve(i / Q);
}


int main() {
	ll N;
	cin >> N >> P >> Q;

	cout << solve(N);

	return 0;
}




/*
* 일정부분만 메모이제이션
* 질문검색 탭에서 알아냄
* 
#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

const int MAX = 5000000;
ll dp[MAX];
ll P, Q;

ll solve(ll i) {
	if (i == 0) return 1;

	if (i >= MAX) return  solve(i / P) + solve(i / Q);

	if (dp[i] != -1) return dp[i];


	return dp[i] = solve( i / P) + solve(i / Q);
}

int main() {

	// -1 로 초기화 한다
	fill(dp, dp + MAX, -1);

	ll N;
	cin >> N>> P >> Q;

	cout << solve(N);
	return 0;
}

*/