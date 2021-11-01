#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {

	int testcase;
	cin >> testcase;

	while (testcase--) {
		string s;
		cin >> s;

		vector<char> left;
		stack<char> right;

		for (auto c : s) {
			if (c == '>') {
				if (right.empty()) continue;
				left.push_back(right.top());
				right.pop();
			}
			else if (c == '<') {
				if (left.empty()) continue;
				right.push(left.back());
				left.pop_back();
			}
			else if (c == '-') {
				if (left.empty()) continue;
				left.pop_back();
			}
			else {
				left.push_back(c);
			}
		}

		for( auto c:left ) cout << c;
		while (!right.empty()) {
			cout << right.top();
			right.pop();
		}
		cout << endl;
	}


	return 0;
}