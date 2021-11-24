#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001
using namespace std;

int id, d[MAX]; // �� ��帶�� ��ȣ ������ȣ �ο�
bool finished[MAX]; //dfs�� �������� Ȯ��
vector<int> a[MAX]; // �׷��� ����
vector<vector<int>> SCC; 
stack<int> s;

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

//DFS�� �� ������ ������ŭ ����
int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	//������� Ȯ��
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		//�湮���� ���� �̿�
		if (d[y] == 0)
			parent = min(parent, dfs(y));
		// ó������ �̿�
		else if (!finished[y])
			parent = min(parent, d[y]);

	}

	//�θ��Ʈ�� �ڱ� �ڽ��ΰ��
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

	cout << "SCC�� ���� " << SCC.size() << endl;
	for (int i = 0; i < SCC.size(); i++) {
		cout << i + 1 << "��° SCC : ";
		for (int j = 0; j < SCC[i].size(); j++)
			cout << SCC[i][j] << " ";
		cout << endl;
	}

	return 0;
}