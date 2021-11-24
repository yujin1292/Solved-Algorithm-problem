#include <iostream>
#include <vector>

using namespace std;

const int INF = 9876543;


int main() {
	// vertex ��, edge �� �ʱ�ȭ
	int v = 5;
	int e = 7;
	int edges[7][3] = {
		{0,1,8},
		{0,2,2},
		{1,2,-1},
		//{1,4,3},
		{4,1,3},
		{2,4,-4},
		{3,2,1},
		{3,0,6}
	};
	
	// 0��° vectex���� �ִ� �Ÿ� ���� �迭
	int dist[5] = { 0, INF, INF, INF, INF };
	bool hasNagativeCycle = false;

	// n-1�� �ݺ��ϸ� �ִܰŸ� ���� but ���� ����Ŭ Ȯ������ n��
	for (int round = 1; round <= v; round++) { 
		cout << "round : " << round << endl;

		// ��� edge üũ (edge relaxation)
		for (int i = 0; i < e; i++) {
			int start = edges[i][0];
			int end = edges[i][1];
			int cost = edges[i][2];

			if (dist[start] == INF) continue;
			if (dist[start] + cost < dist[end]) {
				cout << "using edge " << start << "-> " << end << endl;
				cout << "update " << end << " :" << dist[end]
					<< " -> "<< dist[start] << "+" << cost << "=" << (dist[start] + cost) << endl;
				cout << endl;
				
				dist[end] = dist[start] + cost; // update!
				if (round == v) {
					hasNagativeCycle = true;
				}
			}
		}

	}

	cout << "\n\n0��° vectex������ �ִ� �Ÿ� \n";
	for (int i = 0; i < v; i++) {
		cout << i << " : ";
		if (dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}

	cout << "���� ���� ���� : ";
	if (hasNagativeCycle) cout << " O " << endl;
	else cout << " X  " << endl;

	return 0;
}