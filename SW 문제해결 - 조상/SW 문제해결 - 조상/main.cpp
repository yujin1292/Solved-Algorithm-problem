#include <iostream>
#include <vector>

using namespace std;


int v, e;
int node1, node2;

int answer1, answer2;

class node {
public:	
	
	int right;
	int left;
	int parent;

	bool isSub;

	node() {
		parent = right = left = -1;
		isSub = false;
	}
	void setParent(int me) {
		parent = me;
	}
	void setChild(int child) {
		if (right == -1)
			right = child;
		else if (left == -1)
			left = child;
	}
	int getParent() {
		return parent;
	}
	bool isChild(int child) {
		if (right == child)
			return true;
		else if (left == child)
			return true;
		else
			return false;
	}
	int getLeftChild() {
		return left;
	}
	int getRightChild() {
		return right;
	}
};

node* tree;

int calcSubTree(int root ) {
	

	int r, l;
	r = l = 0;

	if (tree[root].getLeftChild() == -1 && tree[root].getRightChild() == -1) { //leaf node 이면
		return 1;
	}

	if (tree[root].getLeftChild() != -1) {
		l = calcSubTree(tree[root].getLeftChild());
	}

	if (tree[root].getRightChild() != -1) {
		r = calcSubTree(tree[root].getRightChild());
	}


	return r+l+1;
}


void findAncestor() {
	vector<int> ancestor1;
	vector<int> ancestor2;
	int anc = node1;
	
	// 선조들을 벡터에 넣기 
	int temp;
	while (anc != 1) {
		temp = tree[anc].getParent();
		ancestor1.push_back(temp);
		anc = temp;
	}

	anc = node2;
	while (anc != 1) {
		temp = tree[anc].getParent();
		ancestor2.push_back(temp);
		anc = temp;
	}

	//공통 선조 찾기

	int size1 = ancestor1.size();
	int size2 = ancestor2.size();
	bool want = false;

	for (int i = 0; i < size1; i++) {
		if (want)
			break;
		for (int j = 0; j < size2; j++) {
			if (ancestor1[i] == ancestor2[j]) {
				answer1 = ancestor1[i];
				want = true;
				break;
			}
		}

	}



}
void solve() {
	findAncestor();
	answer2 = calcSubTree(answer1);
}



int main() {
	int parent, child;
	int testcase; 
		
	cin >> testcase;
	
	for (int i = 0; i < testcase; i++) {
		cin >> v >> e >> node1 >> node2;//데이터 입력
		
		tree = (node*)malloc(sizeof(node)*(v+1));

		for (int j = 1; j <= v; j++) {
			node temp;
			tree[j] = temp;
		}

		for (int j = 0; j < e; j++) { //간선 수만큼의 데이터 입력 
			cin >> parent >> child;
			tree[parent].setChild(child);
			tree[child].setParent(parent);
		}
		
	
		solve(); //계산

		cout << "#" << i + 1 << " " << answer1 << " " << answer2<<"\n"; // 출력

	}



	return 0;
}