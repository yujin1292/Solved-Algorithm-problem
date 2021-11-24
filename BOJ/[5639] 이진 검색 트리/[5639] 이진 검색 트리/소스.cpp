#include <iostream>
#include <vector>

using namespace std;

vector<int> g;

void printPostOrder(int start, int end) {
	//cout << start << " : " << end << endl;
	if (start == end) {
		cout << g[start]<<"\n";
		return;
	}
	if (start > end) return;

	int mid = end+1;

	for (int i = start; i <= end; i++) {
		if (g[i] > g[start]) {
			mid = i;
			break;
		}
	}

	printPostOrder(start+1, mid-1);
	printPostOrder(mid,  end);

	cout << g[start] << "\n";
}

int main() {


	int num;
	while (cin >> num) {
		g.push_back(num);
	}

	printPostOrder(0, g.size() - 1);

	return 0;
}