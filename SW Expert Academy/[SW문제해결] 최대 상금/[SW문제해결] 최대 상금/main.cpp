#include <iostream>
#include <string>
using namespace std;

int tc, result, cnt;
string num;
int pr[7];

void dfs(int cur, int count) {
	if (count == cnt) {
		result = max(result, stoi(num));
		return;
	}
	for (int i = cur; i < num.size(); i++) {
		for (int j = i + 1; j < num.size(); j++) {
			if (num[i] <= num[j]) {
				swap(num[i], num[j]);
				dfs(i, count + 1);
				swap(num[i], num[j]);
			}
		}
	}
}

int main() {
	cin >> tc;
	for (int i = 1; i <= tc; i++) {

		cin >> num >> cnt;
		result = 0;
		dfs(0, 0);
		cout << "#" << i << " " << result << '\n';
	}
	return 0;
}