#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	int n = 0;
	int m = 0;

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int N2, N5;
		N2 = N5 = i;

		while (N2) {
			if (N2 % 2 == 0) {
				n++;
				N2 /= 2;
			}
			else
				break;
		}
		while (N5) {
			if (N5 % 5 == 0) {
				m++;
				N5 /= 5;
			}
			else
				break;
		}
	}
	
	cout << min(n, m) << endl;
	return 0;
}