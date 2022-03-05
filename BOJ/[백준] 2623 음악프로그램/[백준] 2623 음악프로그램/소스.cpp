#include <iostream>
#include <vector>
#include <queue>
#include <string>


#define MAX 1001

using namespace std;

int n,m, inDegree[MAX];
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;

	//���������� 0 �� ��带 ť�� �����Ѵ�
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		// n ���� �湮�ϱ� ���� ť�� �������� ����Ŭ�� �߻��Ѱ�
		if (q.empty()) {
			cout << 0 << endl;
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];

			//���Ӱ� ���������� 0�� �� ������ ť�� �����Ѵ�.
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << "\n";
	}

}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num, before, now;
		cin >> num >> before;

		for (int j = 1; j < num; j++) {
			cin >> now;
			a[before].push_back(now);
			inDegree[now]++;
			before = now;
		}
	}

	topologySort();

	return 0;
}