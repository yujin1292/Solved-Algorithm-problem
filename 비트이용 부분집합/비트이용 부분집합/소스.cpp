#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<char> list;


int main() {

	list = { 'a','b','c','d','e' };

	for (int i = 0; i < pow(2, list.size()); i++) {
		int t = 1;
		for (int j = 0; j < list.size(); j++) {
			if (i & t)
				cout << list[j] << " ";
			t *= 2;
		}
		cout << endl;
	}

	return 0;
}