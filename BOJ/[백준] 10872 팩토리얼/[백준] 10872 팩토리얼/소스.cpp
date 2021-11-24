#include <iostream>
using namespace std;


int facto(int num) {
	if (num <= 1)
		return 1;
	return (num)*facto(num - 1);
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	cout << facto(num) << "\n";
	return 0;
}