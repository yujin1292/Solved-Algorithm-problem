#include <iostream>
#include <algorithm>
#include <vector>

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


int V, E;
vector<Edge> v;
int set[10001]; // set[i] = j --> i�� �θ�� j �̴�!

int main() {
	cin >> V >> E;

	// �� ������ ���Ե� �׷����� ������� ����

	for (int i = 0; i < V; i++) {
		set[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int a, b, val;
		cin >> a >> b >> val;
		v.push_back(Edge(a, b, val));
	}

	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!isSameParent(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	cout << sum << endl;

	return 0;

}