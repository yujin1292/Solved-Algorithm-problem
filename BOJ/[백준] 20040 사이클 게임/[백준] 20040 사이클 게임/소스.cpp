#include <iostream>

using namespace std;

int parent[500001];
int n, m;

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool isSameParent(int a, int b) {
	return  getParent(a) == getParent(b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		parent[i] = i;
	

	int answer = 0;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (isSameParent(a, b)) {
			answer = i;
			break;
		}
		unionParent(a, b);
	}

	cout << answer;
	return 0;
}