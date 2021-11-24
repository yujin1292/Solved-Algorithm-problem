#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int N;

int g[MAX][2];

vector<int> inOrder;
int result = -1;

void doInOrder(int root) {
	if (g[root][0] != -1)
		doInOrder(g[root][0]);

	inOrder.push_back(root);

	if (g[root][1] != -1)
		doInOrder(g[root][1]);
}

bool print(int root, int endNode) {
	bool isFinished = false;
	result++;
	//cout << root << " ";

	if (g[root][0] != -1) {
		isFinished = print(g[root][0], endNode);
		if (isFinished) return true;
		result++;
		//		cout << root << " ";	
	}

	if (g[root][1] != -1) {
		isFinished = print(g[root][1], endNode);
		if (isFinished) return true;
		result++;
		//		cout << root << " ";
	}

	if (endNode == root)
		return true;

	return false;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int root, lchild, rchild;
		cin >> root >> lchild >> rchild;
		g[root][0] = lchild;
		g[root][1] = rchild;
	}

	doInOrder(1);
	int endNode = inOrder.back();

	print(1, endNode);
	cout << result << endl;

	return 0;
}