#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int num;
	int testcase;
	cin >> testcase;

	while (testcase--) {
		map<string, int> clothes;
		string name, kind;
		cin >> num;

		while (num--) {
			cin >> name >> kind;
			clothes[kind]++;
		}

		map<string, int>::iterator iter = clothes.begin();

		int result = 1;

		for (; iter != clothes.end(); iter++) {
			result *= (iter->second + 1);
		}

		cout << result - 1 << endl;
	}

	return 0;
}