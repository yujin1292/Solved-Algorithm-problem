#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl "\n"

using namespace std;

int main() {
	
	int n;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		sort(str.begin(), str.end());

		do {
			cout << str << endl;
		} while (next_permutation(str.begin(), str.end()));

	}

	return 0;
}