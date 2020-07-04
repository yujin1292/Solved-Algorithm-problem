#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int const VNUM = 5;
vector<int> G[VNUM];
int visit[VNUM];

void dfs(int v) {
	visit[v] = 1;
	int vsize = G[v].size();
	for (int i = 0; i < vsize; i++) {
		int next = G[v][i];
		if (visit[next])
			continue;
		dfs(next);
	}
}

void bfs() {
	// 방문할 vertex 번호를 저장.
	queue<int> q;

	//시작점
	int start = 0;
	q.push(start);
	visit[start] = 1;

	//bfs

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int vsize = G[cur].size();
		for (int i = 0; i < vsize; i++) {
			int nxt = G[cur][i];
			if (visit[nxt])
				continue;
			q.push(nxt);
			visit[nxt] = 1;
		}
	}
}


int main() {

	//vectex 0

	G[0].push_back(1);
	G[0].push_back(2);
	G[0].push_back(4);

	//vertex 4
	G[4].push_back(0);
	G[4].push_back(3);

	//Connected components 
	for (int i = 0; i < VNUM; i++) {
		if (!visit[i])
			dfs(i);
	}



}