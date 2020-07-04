#include <iostream>
#include <stack>

using namespace std;

void print(stack<char> s) {
	int size = s.size();
	for (int i = 0; i < size; i++) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
}
int main() {

	char str[11];
	cin >> str;

	//bool is_changed = true;
	//while (is_changed) {
	//	is_changed = false;

	//	for (int i = 0; i < 9; i++) {
	//		if (str[i] == str[i + 1]) {
	//			is_changed = true;

	//			cout << i << ":" << str << endl;
	//		}

	//		if (is_changed) {
	//			for (int j = i; j < 8 ; j++) {
	//				str[i] = str[i + 2];

	//				cout <<"--> "<<  j << ":" << str << endl;
	//			}

	//		}
	//	}

	//}
	//cout << str << endl;

	stack<char> s;
	

	for (int i = 0; i < 10; i++) {
		
		if (!s.empty() && s.top() == str[i]) {
			print(s);
			s.pop();
			cout << i << ":" << str << endl;
			
		}

		else
			s.push(str[i]);
	}

	print(s);


	return 0;
}