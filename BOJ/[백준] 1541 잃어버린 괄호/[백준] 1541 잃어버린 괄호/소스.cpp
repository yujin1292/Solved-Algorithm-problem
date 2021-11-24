#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	string s;
	cin >> s;

	int num = 0;
	vector<int> numbers;
	bool is_plus = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-') {
			if (is_plus) {
				num += numbers.back();
				numbers.pop_back();
				numbers.push_back(num);
				num = 0;
			}
			else {
				numbers.push_back(num);
				num = 0;
			}
			is_plus = false;
		}
		else if (s[i] == '+') {
			if (is_plus) {
				num += numbers.back();
				numbers.pop_back();
				numbers.push_back(num);
				num = 0;
			}
			else {
				numbers.push_back(num);
				num = 0;
			}
			is_plus = true;			
		}
		else {
			num *= 10;
			num += (s[i] - '0');

			if (i == s.size() - 1) {
				if (is_plus) {
					num += numbers.back();
					numbers.pop_back();
					numbers.push_back(num);
					num = 0;
				}
				else {
					numbers.push_back(num);
					num = 0;
				}
			}
		}
	}


	int result = 0;
	for (int i = 0; i < numbers.size(); i++) {
		result -= numbers[i];
	}
	result += numbers[0]*2;

	cout << result << endl;
	return 0;
}