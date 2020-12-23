#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
stack<string> s;

int solve() {
	int index = 0;
	int temp;

	for (index = 0; index < str.size(); index++) {
		s.push(str.substr(index, 1));
		if (s.top() == ")") {
			temp = 0;
			s.pop();
			if (s.empty())
				return 0;
			while (!s.empty() && s.top() != "(") {
				if (s.top() == "[" || s.top() == "]" || s.top() == "(" || s.top() == ")") // non number
					return 0;
				
				temp += stoi(s.top());
				s.pop();
			}
			if (s.empty())
				return 0;
			s.pop(); //s.top == "("
			temp = (temp == 0) ? 2 : temp *= 2;
			s.push(to_string(temp));
		}
		else if (s.top() == "]") {
			temp = 0;
			s.pop();
			if (s.empty())
				return 0;
			while (!s.empty() && s.top() != "[" ) {
				if (s.top() == "[" || s.top() == "]" || s.top() == "(" || s.top() == ")") 
					return 0;
				temp += stoi(s.top());
				s.pop();
			}
			if (s.empty())
				return 0;
			s.pop(); // s.top == "["
			temp = (temp == 0) ? 3 : temp *= 3;

			s.push(to_string(temp));
		}
	}

	int result = 0;

	while (!s.empty()) {
		if (s.top() == "[" || s.top() == "]" || s.top() == "(" || s.top() == ")")
			return 0;
		result += stoi(s.top());
		s.pop();
	}
	return result;
}



int main() {
	cin >> str;
	cout << solve() << endl;
	return 0;
}