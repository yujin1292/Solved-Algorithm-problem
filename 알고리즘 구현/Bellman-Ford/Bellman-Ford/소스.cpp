#include <iostream>
#include <vector>

using namespace std;

const int INF = 9876543;

// vertex ��, edge �� �ʱ�ȭ
const int v = 5;
const int e = 8;

// start ���� �ִ� �Ÿ� ���� �迭
int dist[v];

int edges[e][3] = {
	{0,1,8},
	{0,2,2},
	{1,2,-1},
	{1,4,-3},
	{4,1,3},
	{2,4,-2},
	{3,2,1},
	{3,0,6}
};


bool bf(int start) {

	bool hasNagativeCycle = false;

	for (int i = 0; i < v; i++) dist[i] = INF;
	dist[start] = 0;

	// n-1�� �ݺ��ϸ� �ִܰŸ� ���� but ���� ����Ŭ Ȯ������ n��
	for (int round = 1; round <= v; round++) {

		// ��� edge üũ (edge relaxation)
		for (int i = 0; i < e; i++) {
			int a = edges[i][0];
			int b = edges[i][1];
			int cost = edges[i][2];

			if (dist[a] == INF) continue;
			if (dist[a] + cost < dist[b]) {

				// dist[a] + cost = start -> a  -> b 
				// dist[b]        = start -> b

				dist[b] = dist[a] + cost; // update!
				if (round == v) {
					hasNagativeCycle = true;
				}
			}
		}

	}

	return hasNagativeCycle;
}

int main() {
	int start = 0;
	bool hasNagativeCycle = bf(start);
	cout << start << " vectex������ �ִ� �Ÿ� \n";

	cout << "-------------------------------------------------\n";
	cout << "vectex \t|";
	for (int i = 0; i < v; i++) 
		cout << i << "\t|";
	cout << endl;
	cout << "-------------------------------------------------\n";

	cout << "dist \t|";
	for (int i = 0; i < v; i++) {
		if (dist[i] == INF) cout << "INF";
		else cout << dist[i];
		cout << "\t|";
	}
	cout << endl;
	cout << "-------------------------------------------------\n";

	cout << endl;
	cout << "���� ����Ŭ ���� : ";
	if (hasNagativeCycle) cout << " O " << endl;
	else cout << " X  " << endl;

	return 0;
}