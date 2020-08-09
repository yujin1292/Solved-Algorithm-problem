#include <iostream>

using namespace std;

int main() {
	double r;
	double pi = 3.14159265358979;

	cin >> r;

	cout << fixed;
	cout.precision(6);

	cout << r * r*pi << " " << r * r * 2.0 << "\n";

	return 0;
}