#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> preOrder;
vector<int> inOrder;

void printPostOrder(pair<int,int> inOrderRange, pair<int,int> preOrderRange){
	int root = preOrder[preOrderRange.first];
	int lchildCount = 0;
	int rchildCount = 0;

	//pre order�� ã�Ƴ� root �������� inOrder����  child count �˾Ƴ�
	for (int i = inOrderRange.first; i <= inOrderRange.second; i++) {
		if (inOrder[i] == root) {
			break;
		}
		lchildCount++;
	}
	rchildCount = (inOrderRange.second - inOrderRange.first) - lchildCount;

	// L child ���
	if (lchildCount != 0) {
		printPostOrder(
			{inOrderRange.first, inOrderRange.first + lchildCount - 1 },//inOrderRange
			{preOrderRange.first+1, preOrderRange.first+lchildCount  } // preOrderRange
		);
	}

	// R child ���
	if (rchildCount != 0) {
		printPostOrder(
			{ inOrderRange.second - rchildCount + 1, inOrderRange.second},//inorderRange
			{ preOrderRange.second - rchildCount + 1 , preOrderRange.second } //preOrderRange
		);
	}


	//root ���
	cout << root << " ";

}

int main() {
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		preOrder.clear();
		inOrder.clear();

		int N, temp;

		cin >> N;

		for (int j = 0; j < N; j++) {
			cin >> temp;
			preOrder.push_back(temp);
		}

		for (int j = 0; j < N; j++) {
			cin >> temp;
			inOrder.push_back(temp);
		}
		
		printPostOrder({ 0, N - 1}, { 0, N - 1} );
		cout << "\n";
	}

	return 0;
}