#include <iostream>

using namespace std;
int solve() {
	int x, y;
	cin >> x >> y;
	if (x < 0) {
		if (y < 0)	return 3;
		else return 2;
	}
	else {
		if (y < 0)	return 4;
		else return 1;
	}
}
int main() {
	
	cout << solve();

	return 0;
}