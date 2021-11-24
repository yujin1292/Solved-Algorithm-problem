#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

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

class Planet {
public:
	int idx;
	int x;
	int y;
	int z;

	Planet(int idx, int x, int y, int z) {
		this->idx = idx;
		this->x = x;
		this->y = y;
		this->z = z;
	}

	int distance(Planet pos) {
		int xDis = abs(x - pos.x);
		int yDis = abs(y - pos.y);
		int zDis = abs(z - pos.z);

		return min(min(xDis, yDis), zDis);
	}
};

bool cmpX(Planet& a, Planet& b) { return a.x < b.x; }
bool cmpY(Planet& a, Planet& b) { return a.y < b.y; }
bool cmpZ(Planet& a, Planet& b) { return a.z < b.z; }

vector<Edge> v;

vector<Planet> planets;
int set[1000001]; // set[i] = j --> i의 부모는 j 이다!

int main() {
	fastio;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		planets.push_back(Planet(i, x, y, z));
		set[i] = i;
	}

	// x 를 기준으로 인접 node만 push
	sort(planets.begin(), planets.end(), cmpX);
	for (int i = 0; i < N - 1; i++) {
		v.push_back(
			Edge(planets[i].idx,
				planets[i + 1].idx,
				planets[i].distance(planets[i + 1]))
		);
	}

	// y 를 기준으로
	sort(planets.begin(), planets.end(), cmpY);
	for (int i = 0; i < N - 1; i++) {
		v.push_back(
			Edge(planets[i].idx,
				planets[i + 1].idx,
				planets[i].distance(planets[i + 1]))
		);
	}

	// z 를 기준으로
	sort(planets.begin(), planets.end(), cmpZ);
	for (int i = 0; i < N - 1; i++) {
		v.push_back(
			Edge(planets[i].idx,
				planets[i + 1].idx,
				planets[i].distance(planets[i + 1]))
		);
	}

	// 크루스칼 실행
	sort(v.begin(), v.end()); // distance로 정렬
	ll sum = 0;
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!isSameParent(set, v[i].node[0], v[i].node[1])) {
			sum += v[i].distance;
			unionParent(set, v[i].node[0], v[i].node[1]);
			count++;
			if (count == N - 1) break; // 더 이상 비교하지않는다..
		}
	}
	cout << sum << endl;

	return 0;
}