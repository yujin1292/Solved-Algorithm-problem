#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s;
vector<int> ans;

void dfs(int v, int cnt, int sum) {
	if (v == 9) {
		if (sum == 100 && cnt == 7) {
			sort(ans.begin(), ans.end());
			for (int i = 0; i < 7; i++) {
				cout << ans[i] << "\n";
			}
			exit(0);
		}
		return;
	}
	ans.push_back(s[v]);
	dfs(v + 1, cnt + 1, sum + s[v]); //»Ì´Â´Ù
	ans.pop_back();

	dfs(v + 1, cnt, sum);//»ÌÁö¾Ê´Â´Ù
}


int main() {
	for (int i = 0; i < 9; i++) {
		int temp;
		cin >> temp;
		s.push_back(temp);
	}

	dfs(0, 0, 0);

	return 0;
}