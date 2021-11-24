#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	string op;
	int num;
	queue<int> q;
	 
	cin >> testcase;
	
	for (int i = 0; i < testcase; i++) {
		cin >> op;
		if (op == "push") {
			cin >> num;
			q.push(num);
		}
		else if (op == "pop") {
			if (q.empty())
				cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (op == "size")
			cout << q.size() <<  "\n";
		else if (op == "empty") {
			if (q.empty())
				cout << 1 <<  "\n";
			else
				cout << 0 <<  "\n";
		}
		else if (op == "front") {
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.front() << "\n";
		}
		else if (op == "back") {
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.back() << "\n";
		}

	}

	return 0;
}