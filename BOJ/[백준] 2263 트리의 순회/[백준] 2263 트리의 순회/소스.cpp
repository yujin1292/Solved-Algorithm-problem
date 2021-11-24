#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inOrder;
vector<int> postOrder;

void printPreOrder(pair<int, int> inOrderRange, pair<int, int> postOrderRange) {

	int root = postOrder[postOrderRange.second];

	// inOrder에서 root를 기준으로 lchild, rchild를 나눈다.
	int lCount, rCount;
	lCount = rCount = 0;

	int inOrderRootIdx = inOrderRange.first;
	for (int i = inOrderRange.first; i <= inOrderRange.second; i++) {
		if (inOrder[i] == root) {
			inOrderRootIdx = i;
			break;
		}
		lCount++;
	}
	rCount = inOrderRange.second - inOrderRootIdx;


	// root
	cout << root << " ";
	// lchild
	if (lCount != 0) {
		printPreOrder(
			{ inOrderRange.first, inOrderRange.first + lCount -1}, // inOrderRange
			{postOrderRange.first, postOrderRange.first + lCount -1}  // postOrderRange
		);
	}
	
	// rchild
	if (rCount != 0) {
		printPreOrder(
			{ inOrderRootIdx +1, inOrderRootIdx + rCount   }, // inOrderRange
			{ postOrderRange.second - rCount , postOrderRange.second-1}  // postOrderRange
		);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		inOrder.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		postOrder.push_back(temp);
	}


	printPreOrder({ 0,n - 1 }, { 0,n - 1 });
	cout << "\n";

	return 0;
}