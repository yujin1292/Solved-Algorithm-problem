#include <iostream>

using namespace std;

long mypower_recursive(long n, long m, long d) {
	if (m == 1) 
		return n % d;

	long n2;

	if (m % 2 == 0) { // Â¦¼ö ÀÏ‹š 
		n2 = mypower_recursive(n, m / 2, d);
		return (n2 * n2) % d; 
	}
	else { // È¦¼ö ÀÏ¶§
		n2 = mypower_recursive(n, m / 2, d);
		return ((n2 * n2 )%d* n) % d;
	}
}


int main() {

	long a, b, c;

	cin >> a >> b >> c;

	cout << mypower_recursive(a, b, c) << "\n";

	return 0;
}