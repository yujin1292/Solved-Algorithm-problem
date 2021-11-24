
#include <queue>
#include<algorithm>
#include <vector>
#include <iostream>
#define INF 99999

using namespace std;
vector<pair<int, int>> g[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int mindist[20001] = { 0 };//�ִܰŸ�
int visited[20001] = { 0 };

void Dijkstra(int s) {
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int d = pq.top().first;
		int next = pq.top().second;

		pq.pop();
		visited[next] = 1;

		for (auto i : g[next]) {
			int dochak = i.first;
			int gajung = i.second;

			if (visited[dochak] == 0 && mindist[dochak] > mindist[next] + gajung) {
				mindist[dochak] = mindist[next] + gajung;
				gajung = mindist[dochak];//����� ����ġ�� �����
				pq.push(make_pair(gajung, dochak));
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//v:��������, E:��������
	int v, E; 
	cin >> v >> E;

	int st;
	cin >> st;

	for (int i = 0; i < E; i++) {
		int a, b, c; 
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));//a-b�Ÿ� c
	}

	//�ʱ�ȭ
	for (int i = 1; i <= v; i++)
		mindist[i] = INF;
	visited[st] = 1;
	mindist[st] = 0;

	Dijkstra(st);

	for (int i = 1; i <= v; i++) {
		if (mindist[i] == INF) cout << "INF\n";
		else cout<<  mindist[i]<<"\n";
	}
	return 0;
}