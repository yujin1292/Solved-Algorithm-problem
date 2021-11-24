#include <iostream>
using namespace std;

int fibonacci(int num) {
	if (num == 1 | num == 2)
		return 1;
	else if (num == 0)
		return 0;

	return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num;
	cin >> num;

	cout << fibonacci(num) << "\n";

	return 0;
}

