#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

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

bool isSameParent( int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b) return true;
	else return false;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) 
		parent.push_back(i);

	for (int i = 0; i < N - 2; i++) {
		int a, b;
		cin >> a >> b;
		unionParent(a-1, b-1);
	}

	int a = parent[0];
	int b = -1;
	for (int i = 0; i < N; i++) {
		if (!isSameParent(a, i)) {
			b = i;
			break;
		}
	}
	cout << a+1 << " " << b+1 << endl;
	return 0;
}