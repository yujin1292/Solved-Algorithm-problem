#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int visit[10];
vector<int> v;
vector<int> nums;


void dfs(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}


	for (int i = 0; i < N; i++) {
		if (visit[i])
			continue;
		//선택
		visit[i] = 1;
		v.push_back(nums[i]);
		dfs(count + 1);
		visit[i] = 0;
		v.pop_back();

	}
}

int main() { //N개중 M개 고른 수열
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int temp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		nums.push_back(temp);
	}
	sort(nums.begin(), nums.end());
	dfs(0);
	return 0;
}