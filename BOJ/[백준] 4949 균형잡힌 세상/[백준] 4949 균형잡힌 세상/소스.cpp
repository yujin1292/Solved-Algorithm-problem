#include <iostream>
#include <stack>
#include <string>

using namespace std;

void solve(string str) {
	stack<char> s;

	for (int i = 0; i < str.size() - 1; i++) {
		//°ýÈ£ ¿­±â 	
		if (str[i] == '(' || str[i] == '[')
			s.push(str[i]);
		//°ýÈ£ ´ÝÈû
		if (str[i] == ')') {
			if (s.empty()) {
				cout << "no\n";
				return;
			}

			if (s.top() == '(')
				s.pop();
			else {
				cout << "no\n";
				return;
			}
		}
		if (str[i] == ']') {
			if (s.empty()) {
				cout << "no\n";
				return;
			}
			if (s.top() == '[')
				s.pop();
			else {
				cout << "no\n";
				return;
			}
		}	
	}
	if (s.empty())
		cout << "yes\n";
	else
		cout << "no\n";
}

int main() {
	string str;

	while (true) {
		getline(cin, str);
		if (str == ".")
			break;
		solve(str);
	}
	return 0;
}
