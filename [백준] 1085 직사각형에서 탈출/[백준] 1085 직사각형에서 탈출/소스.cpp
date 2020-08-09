#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int x, y, w, h;
	vector<int> len;
	cin >> x >> y >> w >> h;

	len.push_back(x);
	len.push_back(y);
	len.push_back(w - x);
	len.push_back(h - y);

	sort(len.begin(), len.end());
	cout << len.front() << endl;


	return 0;
}