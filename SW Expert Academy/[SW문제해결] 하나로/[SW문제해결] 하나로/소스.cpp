#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

typedef long long ll;

using namespace std;

struct pos {
	ll x, y, val;
	pos(ll a, ll b, ll c) {
		x = a;
		y = b;
		val = c;
	}

	bool operator<(const pos &b) const {
		return val < b.val;
	}
};


//루트 저장 
int unf[1001];
int n;

//세율 
double ee;

int Find(int v) {
	if (unf[v] == v) 
		return v;
	else 
		unf[v] = Find(unf[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main() {
	int t = 0;
	scanf("%d", &t);

	for (int tt = 1; tt <= t; tt++) {
		pair<int, int> map[1001];
		vector<pos> v;
		memset(unf, 0, sizeof(unf));

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			unf[i] = i;
			scanf("%d", &map[i].first);
		}

		for (int i = 0; i < n; i++) {
			scanf("%d", &map[i].second);
		}

		scanf("%lf", &ee);

		ll a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				a = pow((map[i].first - map[j].first), 2);
				b = pow((map[i].second - map[j].second), 2);
				ll val = a + b;
				v.push_back(pos(i, j, val));
			}
		}

		sort(v.begin(), v.end());

		ll ans = 0;
		for (int i = 0; i < v.size(); i++) {
			if (Find(v[i].x) != Find(v[i].y)) {
				Union(v[i].x, v[i].y);
				ans += v[i].val;
			}
		}


		printf("\n#%d %0.f", tt, (double)(ans*ee));

	}
	return 0;
}