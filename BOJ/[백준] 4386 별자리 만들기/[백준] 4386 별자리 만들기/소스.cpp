#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Edge {
public:
	int node[2];
	double distance;

	Edge(int a, int b, double distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};


const int MAX = 10001;

int n;
int set[MAX];
pair<double, double> pos[MAX];
vector<Edge> v;

int getParent(int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) set[b] = a;
	else set[a] = b;
}

bool isSameParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

double getDistance(int i, int j) {
	double x = pow(pos[i].first - pos[j].first, 2);
	double y = pow(pos[i].second - pos[j].second, 2);
	return sqrt(x + y);
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> pos[i].first >> pos[i].second;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			v.push_back(Edge(i, j, getDistance(i, j)));
		}
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) set[i] = i;
	
	double sum = 0.0;
	for (int i = 0; i < v.size(); i++) {
		if (!isSameParent(v[i].node[0], v[i].node[1])) {
			sum += v[i].distance;
			unionParent(v[i].node[0], v[i].node[1]);
		}
	}

	cout << round(sum * 100) / 100 << "\n";

	return 0;
}