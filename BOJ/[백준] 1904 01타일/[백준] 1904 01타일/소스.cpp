#include <iostream>
#define MAX 1000001
using namespace std;

int d[MAX];
int N;

int main() {
	cin >> N;
	d[0] = 0;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= N; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 15746;
	}
	cout << d[N] << endl;
	
}