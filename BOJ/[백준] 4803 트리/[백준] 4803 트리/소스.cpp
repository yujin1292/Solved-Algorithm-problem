#include <iostream>
#include <string>
#include <set>

using namespace std;

const int MAX = 501;

int parent[MAX];

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
	a = getParent(a);
	b = getParent(b);

	if (a == b) return true;
	else return false;
}

void solve(int n , int m, int test_case) {

	// init 
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	// ����Ŭ�� ���� Ʈ���� �θ�  �ߺ����� �����Ѵ�. ( Ʈ������ �����ϱ� ���� )
	set<int> root_having_cycle;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		bool sameParent = isSameParent(a, b);
		unionParent(a,b);

		// ����Ŭ�� �߻��Ͽ����Ƿ� Ʈ�� �������� ������ �ش� �θ� �����Ѵ�
		if( sameParent) root_having_cycle.insert(getParent(a));
	}


	// Ʈ�� ���� ����
	// parent �迭�� ������Ʈ�� �ȵǾ����� �� �����Ƿ� ������ ���� �Լ��� �̿��� �����Ѵ�
	set<int> tree_root;
	for (int i = 1; i <= n; i++) {
		bool is_not_tree = false;
		for (int c : root_having_cycle) { // Ʈ������ ������ vertex���� ��ȸ�ϸ� üũ
			if (isSameParent(c, i)) {
				is_not_tree = true;
				break;
			}
		}

		// �ߺ����� �ڷᱸ���� �̿��߱� ������  �ߺ�üũ���� 
		// Ʈ������ �˸��� tree_root�� insert
		if (!is_not_tree) {
			tree_root.insert(getParent(i));
		}
	}


	// tree ������ ���� ���� ��� 
	cout << "Case " << test_case << ": ";
	if (tree_root.size()  == 0) {
		cout << "No trees.\n";
	}
	else if (tree_root.size() == 1) {
		cout << "There is one tree.\n";
	}
	else {
		cout << "A forest of " << tree_root.size() << " trees.\n";
	}
}

int main() {

	int n, m;
	int test_case = 1;

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		solve(n, m, test_case);
		test_case++;
	}
	return 0;
}