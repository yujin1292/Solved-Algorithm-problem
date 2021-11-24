#include <iostream>
#include <vector>

using namespace std;

int getParent(vector<int>& parent, int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(vector<int>& parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool isSameParent(vector<int>& parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b) return true;
	else return false;
}

int main() {

	vector<int> parent(11);

	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}

	unionParent(parent, 1, 2); // 1과 2 연결
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 4, 10);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	vector<vector<int>> query = { {1,5}, {2,4} ,{1,8} };

	for (auto q : query) {
		cout << q[0] << "과" << q[1] << "은 연결되어있나요?" << endl;
		if (isSameParent(parent, q[0], q[1])) cout << "네 " << endl;
		else cout << "아니요" << endl;
		
		cout << "----------------------" << endl;
	}


	unionParent(parent, 1, 8);
	cout << "\n1과 8 연결\n" << endl;
	for (auto q : query) {
		cout << q[0] << "과" << q[1] << "은 연결되어있나요?" << endl;
		if (isSameParent(parent, q[0], q[1])) cout << "네 " << endl;
		else cout << "아니요" << endl;

		cout << "----------------------" << endl;
	}


	return 0;
}