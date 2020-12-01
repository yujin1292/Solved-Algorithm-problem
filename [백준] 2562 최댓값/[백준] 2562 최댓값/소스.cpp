#include <iostream>
using namespace std;

int v[9];

int main() {

	for (int i = 0; i < 9; i++)
		cin >> v[i];
	int index, val;
	val = -1;
	for (int i = 0; i < 9; i++) {
		if (val < v[i]) {
			val = v[i];
			index = i;
		}
	}
	cout << val << endl;
	cout << index +1 << endl;

}