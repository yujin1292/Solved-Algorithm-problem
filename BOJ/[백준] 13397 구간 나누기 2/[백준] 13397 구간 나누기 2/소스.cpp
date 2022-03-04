#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;


bool isPossable(int value) {

	int min = v[0];
	int max = v[0];
	int count = 1;

	for (int i = 1; i < N; i++) {
		
		if (v[i] < min) min = v[i];
		if (v[i] > max) max = v[i];

		int cur = max - min;

		if (cur > value) {
			min = v[i];
			max = v[i];
			count++;
			if (count > M) return false;
		}
	}

//	cout << value << ": " << count << endl;
	return count <= M ;
}


int main() {

	int start = 0;
	int end = -1;
	int min = 50001;

	cin >> N >> M;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
		if (end < num) end = num;
		if (min > num) min = num;
	}
	end -= min;

	int mid;
	while (start <= end) {
		
		mid = (start + end) / 2;

		if (isPossable(mid)) { // ´õ ÁÙ¿©ºÁ.>! 
			end = mid - 1;
		}
		else {
			start = mid+1;
		}
	}

	cout << start;

	return 0;
}