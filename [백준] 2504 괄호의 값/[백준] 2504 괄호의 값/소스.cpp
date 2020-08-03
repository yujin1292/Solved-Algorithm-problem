#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	
	stack< pair<char, int> >s;

	string input;
	cin >> input;

	int size = input.length();

	for (int i = 0; i < size; i++) {
		//open
		if (input[i] == '(') { // push {(, 0} 
			s.push({ input[i] , 0});
		}
		else if (input[i] == '[') {
			s.push({ input[i], 0 } );
		}
		//close
		else if (input[i] == ')') {
			bool Check = false;
			int sSize = s.size();
			int temp = 0;

			for (int j = 0; j < sSize; j++) {
				temp += s.top().second;
				if (s.top().first == '(') {
					Check = true;
					s.pop();
					break;
				}
				s.pop();

			}

			if (Check) {
				if (temp == 0)
					temp = 1;
				s.push({ ' ', temp * 2 });
			}
			else { // ´Ý´Â°ýÈ£¸¦ Ã£Áö¸øÇßÀ½ 
				cout << 0 << "\n";
				return 0;
			}
			
		}
		else if (input[i] == ']') {
			bool Check = false;
			int sSize = s.size();
			int temp = 0;

			for (int j = 0; j < sSize; j++) {
				temp += s.top().second;
				if (s.top().first == '[') {
					Check = true;
					s.pop();
					break;
				}
				s.pop();

			}

			if (Check) {
				if (temp == 0)
					temp = 1;
				s.push({ ' ', temp * 3 });
			}
			else { // ´Ý´Â°ýÈ£¸¦ Ã£Áö¸øÇßÀ½ 
				cout << 0 << "\n";
				return 0;
			}

		}
		else {
			cout << 0 << "\n";
			return 0;
		}

	}

	int result = 0;
	while (!s.empty()) {
		if (s.top().first != ' ') {
			cout << 0 << "\n";
			return 0;
		}
		else{
			result += s.top().second;
			s.pop();
		}

	}
	cout << result << "\n";
	return 0;
}