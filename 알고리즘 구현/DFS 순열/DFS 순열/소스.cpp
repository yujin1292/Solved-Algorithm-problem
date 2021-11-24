#include <iostream>
#include <vector>

using namespace std;

int visit[6];
vector<int> result;

int c = 0;

void dfs(int v, int count) {

	visit[v] = 1;

	if (count == 3) {
		cout << ++c << " : ";
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= 5; i++) {
		if (visit[i] == 1) {
			continue;
		}
		else {
			result.push_back(i);
			dfs(i, count + 1);

			//원상복구
			visit[i] = 0;
			result.pop_back();
		}

	}
}

int main() {

	for (int i = 1; i <= 5; i++) {
		result.push_back(i);
		dfs(i, 1);
		visit[i] = 0;
		result.pop_back();
	}

	return 0;
}