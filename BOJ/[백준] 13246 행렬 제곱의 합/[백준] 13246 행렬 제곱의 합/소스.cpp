#include <iostream>
#include <vector>
#include <map>

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long 
#define matrix vector<vector<int>>
using namespace std;

map<ll, matrix > squared;

matrix A;

// 행렬 간 계산
matrix multiply(matrix a, matrix b) {
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
				sum += ((a[i][idx] * b[idx][j]) % 1000);
				sum %= 1000;
			}
			row.push_back(sum);
		}
		result.push_back(row);
	}

	return result;
}

matrix addI(matrix a) {
	matrix result;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j < n; j++) {
			int temp = a[i][j];
			if( i == j)
				temp = (a[i][j] + 1) % 1000;

			row.push_back(temp);
		}
		result.push_back(row);
	}
	return result;
}

matrix sum(matrix a, matrix b) {

	int n = b.size();

	matrix result;

	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j < n; j++) {
			int temp = (a[i][j] + b[i][j]) % 1000;
			row.push_back(temp);
		}
		result.push_back(row);
	}

	return result;
}


// 행렬 A 를 가지고 연산
matrix square(ll k) {
	if (k == 1) return A;

	if (squared.find(k) != squared.end()) {
		return squared[k];
	}

	if (k % 2) { // 홀수
		auto temp = multiply(multiply(square( k / 2), square( k / 2)), A);
		squared[k] = temp;
		return temp;
	}
	else {
		auto temp = multiply(square( k / 2), square( k / 2));
		squared[k] = temp;
		return temp;
	}
}

matrix solve(ll b) {

	if (b == 1) return A;

	if (b % 2) {
		return sum( multiply(solve(b / 2), addI(square(b / 2))), square(b));
	}
	else {
		return multiply(solve(b / 2), addI(square(b / 2)));
	}
}

int main() {

	int n;
	ll b;
	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		vector<int> row(n);
		for (int j = 0; j < n; j++) {
			cin >> row[j];
			row[j] %= 1000;
		}
		A.push_back(row);
	}

	vector<vector<int>> result = solve(b);
	for (vector<int> row : result) {
		for (int e : row) {
			cout << e << " ";
		}
		cout << endl;
	}

	return 0;
}