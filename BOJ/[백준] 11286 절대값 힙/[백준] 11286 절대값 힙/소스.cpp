#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		int aa = a;
		int bb = b;

		if (a < 0)	aa *= -1;
		if (b < 0)	bb *= -1;

		if (aa == bb) //절대값이 같을경우
			return a > b;

		return  aa > bb ;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int,vector<int>, cmp > queue;

	int N;
	cin >> N;

	while (N--) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			if (queue.empty())
				cout << "0\n";
			else {
				cout << queue.top() << "\n";
				queue.pop();
			}
		}
		else 
			queue.push(temp);
		
	}

	return 0;
}