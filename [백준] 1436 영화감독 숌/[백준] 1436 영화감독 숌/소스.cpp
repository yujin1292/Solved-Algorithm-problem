#include <iostream>
#include <string>

using namespace std;

int n;
bool isItOk(int num) {
	string s = to_string(num);

	for (int i = 0; i < s.size()-2; i++) {
		if (s[i] == '6' && s[i+1] == '6' && s[i+2] == '6' ) {
			return true;
		}
	}
	return false;
}
int main() {
	cin >> n;
	int count = 0;
	for (int i = 666;  ; i++) {
		if (isItOk(i)) {
			count++;
			//cout << i << endl;
		}
		if (count == n) {
			cout << i << endl;
			break;
		}
	}
}