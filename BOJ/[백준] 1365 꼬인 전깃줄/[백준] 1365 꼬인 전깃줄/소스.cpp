#include <vector>
#include <iostream>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;


int n, first, k;

vector <int> vec;

int main(void) {
	fastio;

	cin >> n;
	cin >> first;
	vec.push_back(first);
	for (int i = 1; i < n; i++) {
		cin >> k;
		if (vec.back() >= k) {
			*lower_bound(vec.begin(), vec.end(), k) = k;
		}
		else {
			vec.push_back(k);
		}
	}

	cout << n-vec.size();

	return 0;
}