#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

vector<int> G[MAX];
int visit[MAX];
int computer;
int edge;
int vi;

void dfs(int com) {
	visit[com] = 1;

	for (int i = 0; i < G[com].size(); i++) {
		if (visit[G[com][i]])
			continue;
		dfs(G[com][i]);
		vi++;
	}
}


int main() {

	cin >> computer >> edge;
	int a, b;
	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1);
	cout << vi;
	return 0;
}