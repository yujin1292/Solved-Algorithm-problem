#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long

using namespace std;

const int MAX = 1001;
const ll INF = 1000 * 100000 + 2;
int N, M, start, dest;

vector<pair<int, ll>> v[MAX]; // v[a] = (b,c) : a���� b���� c��  ������� �̵� ����
ll dist[MAX];
vector<int> route[MAX];


void dijkstra(int start) {

	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,start }); // ������� �Ÿ�, ���� ��ġ

	while (!q.empty()) {

		int distance = q.top().first;
		int stopover = q.top().second;

		q.pop();

		// �����ϰ����ϴ� src -> stopover�� �Ÿ���  ���� distacece���� �ָ� �ǳʶٱ� 
		if (dist[stopover] < distance) continue;

		for (int i = 0; i < v[stopover].size(); i++) {
			int next = v[stopover][i].first;

			int newCost = distance + v[stopover][i].second; // start -> stopover -> next
			if (dist[next] >  newCost) {
				dist[next] =  newCost;

				q.push({ dist[next],next });
				route[next] = { route[stopover].begin(), route[stopover].end() };
				route[next].push_back(next);
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int s, d, cost;
		cin >> s >> d >> cost;
		v[s].push_back({ d,cost });
	}
	cin >> start >> dest;

	dijkstra(start);
	

	cout << dist[dest] << "\n";
	cout << route[dest].size()+1 << "\n";
	cout << start << " ";
	for (int v : route[dest])
		cout << v << " ";

	cout << endl;
	return 0;
}