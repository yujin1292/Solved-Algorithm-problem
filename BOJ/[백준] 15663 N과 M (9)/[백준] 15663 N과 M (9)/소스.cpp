#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> numbers;
set<vector<int>> results;

int N, M;

int visit[9];

void dfs(int count, vector<int> result) {
	if (count == M) {
		results.insert(result);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		result.push_back(numbers[i]);
		dfs(count+1, result);

		visit[i] = 0;
		result.pop_back();
	}
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}
	vector<int> result;

	dfs(0, result);

	for (vector<int> v : results) {
		for (int element : v) 
			cout << element << " ";
		cout << "\n";
	}

	return 0;
}