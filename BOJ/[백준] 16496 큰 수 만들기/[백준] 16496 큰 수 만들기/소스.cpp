#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	int as = a.size(), bs = b.size();
	int cnt = as * bs;
	for (int i = 0; i < cnt; i++) {
		if (a[i % as] != b[i % bs]) {
			return a[i % as] > b[i % bs];
		}
	} 
	return a.size() < b.size();
}

int main() {
	int N;
	vector<string> result;

	string input;
	cin >> N;
	while (N--) {
		cin >> input;
		result.push_back(input);
	}
	
	sort(result.begin(), result.end(), cmp);

	if (result[0] == "0")
		cout << "0\n";
	else {
		for (auto it : result)
			cout << it;
	}
	return 0;
}