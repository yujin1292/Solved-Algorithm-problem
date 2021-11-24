#include <iostream>

using namespace std;

int result[12];

int find(int num) {
	if (num <= 3)
		return result[num];
	else {
		if (result[num] == 0)
			return find(num - 1) + find(num - 2) + find(num - 3);
		else
			return result[num];
	}
}

int main() {
	result[1] = 1;
	result[2] = 2;
	result[3] = 4;

	int T,num;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> num;
		cout << find(num) <<"\n";
	}
}