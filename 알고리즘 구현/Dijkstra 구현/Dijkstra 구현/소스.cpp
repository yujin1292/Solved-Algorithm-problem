#include <iostream>

using namespace std;


int number = 6;
int INF = 1000000000;
bool visit[6];
int d[6];

int a[6][6] = {
	{0,2,4,1,INF,INF},
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0}
};

// 최소거리를 가지는 정점 반환
int getSmalIndex() {
	int min = INF;
	int index = 0;

	for (int i = 0; i < number; i++) {
		if (d[i] < min && !visit[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}


void dijkstra(int start) {
	for (int i = 0; i < number; i++)
		d[i] = a[start][i];

	visit[start] = true;

	for (int i = 0; i < number - 2; i++) {
		int current = getSmalIndex();
		visit[current] = true;
		for (int j = 0; j < 6; j++) {
			if (visit[j])
				continue;
			
			if (d[current] + a[current][j] < d[j])
				d[j] = d[current] + a[current][j];
		}
	}

}

int main() {
	dijkstra(0);
	for (int i = 0; i < number; i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	return 0;
}