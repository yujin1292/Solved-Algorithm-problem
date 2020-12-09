#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int N, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int sum = 0;
	int result = 0;
	for (int i = 0; i < N; i++) {
		sum += v[i];
		result += sum;
	}
	cout << result;
	return 0;
}