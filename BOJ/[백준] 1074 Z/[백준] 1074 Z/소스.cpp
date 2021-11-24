#include <iostream>
#include <math.h>

using namespace std;


int find(int N, int r, int c) {
	if (N == 1) {
		if (r == 0 && c == 0) return 0;
		else if (r == 0 && c == 1) return 1;
		else if (r == 1 && c == 0) return 2;
		else return 3;
	}

	int power = pow(2, N - 1);
	int area;

	if (r/ power == 0 && c / power == 0) area =  0;
	else if (r / power == 0 && c / power == 1) area = 1;
	else if (r / power == 1 && c / power == 0) area = 2;
	else area = 3;
	
	return power * power * area + find(N - 1, r%power, c%power);
}

int main() {

	int N, r, c;
	cin >> N >> r >> c;
	cout << find(N, r, c);

	return 0;
}