#include <iostream>
#include <string>
using namespace std;

int M = 1234567891;
int r = 31;

int main() {
	int len;
	string s;
	cin >> len >> s;
	
	long long result = 0;
	long long R = 1;

	for (int i = 0; i < len; i++) {
		result += ((s[i] - 'a' + 1) * R);
		R *= r;
		R %= M;
		result %= M;
	}
	cout << result << endl;
	return 0;
}