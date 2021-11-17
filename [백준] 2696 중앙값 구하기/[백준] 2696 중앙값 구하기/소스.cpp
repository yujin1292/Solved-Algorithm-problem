#include<algorithm>
#include<queue>
#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	vector< vector<int> > results;

	while (T--) {

		int N;
		cin >> N;
		int num;


		priority_queue<int> maxheap;
		priority_queue<int, vector<int>, greater<int>> minheap;
		vector<int> result;
		for (int i = 1; i <= N; i++) {
			cin >> num;
			if (maxheap.size() == 0) {
				maxheap.push(num);
			}
			else if (minheap.size() == 0) {
				if (maxheap.top() > num) {
					minheap.push(maxheap.top());
					maxheap.pop();
					maxheap.push(num);
				}
				else minheap.push(num);
			}
			else if (minheap.size() > maxheap.size()) {
				if (minheap.top() > num) maxheap.push(num);
				else {
					maxheap.push(minheap.top());
					minheap.pop();
					minheap.push(num);
				}
			}
			else if (maxheap.size() > minheap.size()) {
				if (maxheap.top() >= num) {
					minheap.push(maxheap.top());
					maxheap.pop();
					maxheap.push(num);
				}
				else  minheap.push(num);
			}
			else { //둘의 사이즈가 같다
				if (minheap.top() > num) maxheap.push(num);
				else {
					maxheap.push(minheap.top());
					minheap.pop();
					minheap.push(num);
				};
			}

			if (i % 2 == 1)
				result.push_back(maxheap.top());
		}
		results.push_back(result);
	}

	for (auto result : results) {
		cout << result.size() << "\n";
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
			if (i %10== 9) cout << "\n";
		}
		if (result.size() % 10 != 9) cout << "\n";
	}
}