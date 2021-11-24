#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

int getParent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);

	if (a < b) set[b] = a;
	else set[a] = b;
}

bool isSameParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);

	return a == b;
}

class Edge {
public:
	int node[2];
	int distance;

	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};



vector<Edge> v;
int set[1000001]; // set[i] = j --> i의 부모는 j 이다!

int main() {
	fastio;

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		set[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, val;
		cin >> a >> b >> val;
		v.push_back(Edge(a-1, b-1, val));
	}

	sort(v.begin(), v.end());

	ll sum = 0;
	int maxCost = 0;
	// 연결 중에 가장 큰 유지비를 가지는 거리를 끊는다! ( 스패닝트리가 두개로 나뉨 )
	for (int i = 0; i < v.size(); i++) {
		if (!isSameParent(set, v[i].node[0], v[i].node[1])) {
			sum += v[i].distance;
			unionParent(set, v[i].node[0], v[i].node[1]);
			if (maxCost < v[i].distance) maxCost = v[i].distance;
		}
	}
	
	cout << sum - maxCost << endl;

	return 0;
}