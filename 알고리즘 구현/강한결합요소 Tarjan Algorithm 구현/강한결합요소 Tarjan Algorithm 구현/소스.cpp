#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001
using namespace std;

int id, d[MAX]; // 각 노드마다 번호 고유번호 부여
bool finished[MAX]; //dfs가 끝났는지 확인
vector<int> a[MAX]; // 그래프 정보
vector<vector<int>> SCC; 
stack<int> s;

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

//DFS는 총 정점의 개수만큼 실행
int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	//인접노드 확인
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		//방문하지 않은 이웃
		if (d[y] == 0)
			parent = min(parent, dfs(y));
		// 처리중인 이웃
		else if (!finished[y])
			parent = min(parent, d[y]);

	}

	//부모노트가 자기 자신인경우
	if (parent == d[x]) {
		vector<int> scc;
		while (true) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x)
				break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main(void) {
	int v = 11;

	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);

	for (int i = 1; i <= v; i++) {
		if (d[i] == 0)
			dfs(i);
	}

	cout << "SCC의 개수 " << SCC.size() << endl;
	for (int i = 0; i < SCC.size(); i++) {
		cout << i + 1 << "번째 SCC : ";
		for (int j = 0; j < SCC[i].size(); j++)
			cout << SCC[i][j] << " ";
		cout << endl;
	}

	return 0;
}