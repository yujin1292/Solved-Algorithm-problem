#include <iostream>
#include <string>
using namespace std;

void isPalindrome(string s) {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size()-1 - i]) {
			cout << "no\n";
			return;
		}
	}
	cout << "yes\n";
}

int main() {
	string s;
	while (true) {
		cin >> s;
		if (s == "0")
			break;
		isPalindrome(s);
	}
	return 0;
}