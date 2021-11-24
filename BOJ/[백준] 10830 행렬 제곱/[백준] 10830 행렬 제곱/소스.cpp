#include <iostream>
#include <vector>
#include <map>

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long 
using namespace std;

map<ll, vector<vector<int>> > squared;

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b) {
	// a -> m X k
	// b -> k X n

	int m = a.size();
	int k = b.size();
	int n = b[0].size();

	vector<vector<int>> result;

	for (int i = 0; i < m; i++) {
		vector<int> row;
		for (int j = 0; j < n; j++) {
			int sum = 0;
			for (int idx = 0; idx < k; idx++) {
				sum += ((a[i][idx] * b[idx][j])%1000);
				sum %= 1000;
			}
			row.push_back(sum);
		}
		result.push_back(row);
	}

	return result;
}

vector<vector<int>> square(vector<vector<int>> a, ll k) {
	if (k == 1) return a;
	
	if (squared.find(k) != squared.end() ) {
		return squared[k];
	}

	if (k % 2) { // È¦¼ö
		auto temp = multiply( multiply(square(a, k / 2), square(a, k / 2)), a);
		squared[k] = temp;
		return temp;
	}
	else {
		auto temp = multiply(square(a, k / 2), square(a, k / 2));
		squared[k] = temp;
		return temp;
	}
}

int main() {

	vector<vector<int>> a;
	
	int n;
	ll b;
	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		vector<int> row(n);
		for (int j = 0; j < n; j++) {
			cin >> row[j];
			row[j] %= 1000;
		}
		a.push_back(row);
	}

	vector<vector<int>> result = square(a, b);
	for (vector<int> row : result) {
		for (int e : row) {
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}