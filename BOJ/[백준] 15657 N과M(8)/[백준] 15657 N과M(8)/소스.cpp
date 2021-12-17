#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> num;

void dfs(int cur, int count, vector<int> result) {

	if (count == M) {
		for (int r : result) cout << r << " ";
		cout << endl;
		return;
	}

	for (int i = cur; i < N; i++) {
		result.push_back(num[i]);
		dfs(i, count + 1, result);
		result.pop_back();
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		num.push_back(temp);
	}

	sort(num.begin(), num.end());

	vector<int> temp;
	dfs(0, 0, temp);

	return 0;
}