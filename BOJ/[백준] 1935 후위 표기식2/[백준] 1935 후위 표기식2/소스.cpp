#include <map>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main() {

	map<char, int> oprand;
	string s;
	int op;
	cin >> op >> s;

	int c = 'A';
	while (op--) {
		int temp;
		cin >> temp;
		oprand[c] = temp;
		c++;
	}

	stack<double> st;
	for (auto ch : s) {
		if ('A' <= ch && ch <= 'Z') {
			st.push(oprand[ch]);
		}
		else{
			double b = st.top();
			st.pop();
			double a = st.top();
			st.pop();
			if (ch == '+') st.push(a + b);
			else if (ch == '-') st.push(a - b);
			else if (ch == '/') st.push(a / b);
			else if (ch == '*') st.push(a * b);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top() << endl;

	return 0;
}