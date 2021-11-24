#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int N, M;

void print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";

}


void dfs(int count) {
	if (count == M) {
		print();
		return;
	}


	for (int i = 1; i <= N; i++) {
		//i ¼±ÅÃ
		if (!v.empty() && i < v.back())
			continue;
		v.push_back(i);
		dfs(count + 1);
		v.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	dfs(0);
}