#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
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
	ll distance;

	Edge(int a, int b, ll distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};


int V;
vector<Edge> v;
int set[10001]; // set[i] = j --> i의 부모는 j 이다!

int main() {
	cin >> V;

	for (int i = 0; i < V; i++) {
		set[i] = i;
	}

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			ll val;
			cin >> val;
			if (i < j) v.push_back(Edge(i, j, val));
		}
	}

	sort(v.begin(), v.end());

	ll sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!isSameParent(set, v[i].node[0], v[i].node[1])) {
			sum += v[i].distance;
			unionParent(set, v[i].node[0], v[i].node[1]);
		}
	}

	cout << sum << endl;

	return 0;
}