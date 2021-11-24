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

	unionParent(parent, 1, 2); // 1�� 2 ����
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 4, 10);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	vector<vector<int>> query = { {1,5}, {2,4} ,{1,8} };

	for (auto q : query) {
		cout << q[0] << "��" << q[1] << "�� ����Ǿ��ֳ���?" << endl;
		if (isSameParent(parent, q[0], q[1])) cout << "�� " << endl;
		else cout << "�ƴϿ�" << endl;
		
		cout << "----------------------" << endl;
	}


	unionParent(parent, 1, 8);
	cout << "\n1�� 8 ����\n" << endl;
	for (auto q : query) {
		cout << q[0] << "��" << q[1] << "�� ����Ǿ��ֳ���?" << endl;
		if (isSameParent(parent, q[0], q[1])) cout << "�� " << endl;
		else cout << "�ƴϿ�" << endl;

		cout << "----------------------" << endl;
	}


	return 0;
}