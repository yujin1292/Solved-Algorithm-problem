#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	vector<int> coin;

	cin >> n >> k;

	while (n--) {
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}
	int result = 0;

	int kk = k;
	while (kk) {
		int j;
		for ( j = 0; j < coin.size() && coin[j] <= kk ; j++);
		j--;

		result += (kk / coin[j]);
		kk = (kk % coin[j]);
	}

	cout << result << endl;

	return 0;
}