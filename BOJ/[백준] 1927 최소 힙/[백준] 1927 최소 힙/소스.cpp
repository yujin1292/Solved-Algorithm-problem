#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	multiset<int> q;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) {
			if (q.size() == 0) {
				cout << "0\n";
			}
			else {
				cout << *q.begin() << "\n";
				q.erase(q.begin());
			}

		}
		else {
			q.insert(num);
		}
	}
}