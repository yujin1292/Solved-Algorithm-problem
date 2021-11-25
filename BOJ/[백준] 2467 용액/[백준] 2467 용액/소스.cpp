#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v;
	
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}


	int start = 0;
	int end = N - 1;
	int mixed = abs(v.back() + v.front());

	int left = start;
	int right = end;

	while ( start < end) {
		if ( v[start] + v[end] == 0 ) {
			left = start;
			right = end;
			break;
		}

		if ( abs( v[start] + v[end] ) <=  mixed) {
			mixed = abs( v[end] + v[start] );
			left = start;
			right = end;
		}

		if ( v[end] + v[start] < 0) {
			start++;
		}
		else {
			end--;
		}

	}

	cout << v[left] << " " << v[right];

	return 0;
}