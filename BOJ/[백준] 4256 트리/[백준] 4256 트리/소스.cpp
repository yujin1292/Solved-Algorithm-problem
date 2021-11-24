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

	//pre order로 찾아낸 root 기준으로 inOrder에서  child count 알아냄
	for (int i = inOrderRange.first; i <= inOrderRange.second; i++) {
		if (inOrder[i] == root) {
			break;
		}
		lchildCount++;
	}
	rchildCount = (inOrderRange.second - inOrderRange.first) - lchildCount;

	// L child 출력
	if (lchildCount != 0) {
		printPostOrder(
			{inOrderRange.first, inOrderRange.first + lchildCount - 1 },//inOrderRange
			{preOrderRange.first+1, preOrderRange.first+lchildCount  } // preOrderRange
		);
	}

	// R child 출력
	if (rchildCount != 0) {
		printPostOrder(
			{ inOrderRange.second - rchildCount + 1, inOrderRange.second},//inorderRange
			{ preOrderRange.second - rchildCount + 1 , preOrderRange.second } //preOrderRange
		);
	}


	//root 출력
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