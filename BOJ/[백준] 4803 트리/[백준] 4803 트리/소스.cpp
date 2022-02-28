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

	// 사이클을 가진 트리의 부모를  중복없이 저장한다. ( 트리에서 제외하기 위함 )
	set<int> root_having_cycle;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		bool sameParent = isSameParent(a, b);
		unionParent(a,b);

		// 사이클이 발생하였으므로 트리 개수에서 제외할 해당 부모를 저장한다
		if( sameParent) root_having_cycle.insert(getParent(a));
	}


	// 트리 개수 세기
	// parent 배열은 업데이트가 안되어있을 수 있으므로 무조건 관련 함수를 이용해 접근한다
	set<int> tree_root;
	for (int i = 1; i <= n; i++) {
		bool is_not_tree = false;
		for (int c : root_having_cycle) { // 트리에서 제외할 vertex들을 순회하며 체크
			if (isSameParent(c, i)) {
				is_not_tree = true;
				break;
			}
		}

		// 중복없는 자료구조를 이용했기 때문에  중복체크없이 
		// 트리임을 알리는 tree_root에 insert
		if (!is_not_tree) {
			tree_root.insert(getParent(i));
		}
	}


	// tree 개수에 따른 정답 출력 
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