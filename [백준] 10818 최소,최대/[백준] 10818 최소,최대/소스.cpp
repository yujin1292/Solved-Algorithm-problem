#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	int N;
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cout << v.front() << " " << v.back() << endl;


	return 0;
}