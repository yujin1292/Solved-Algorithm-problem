#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int temp;
	vector<int> length;

	while (true) {
		length.clear();
		for (int i = 0; i < 3; i++) {
			cin >> temp;
			length.push_back(temp);
		}
		if (length[0] == 0 && length[1] == 0 && length[2] == 0) break;
		
		sort(length.begin(), length.end());
		
		if ( ( pow(length[0],2)  + pow(length[1],2) ) == ( pow(length[2],2) ) )
			cout << "right\n";
		else
			cout << "wrong\n";
	}

	return 0;
}