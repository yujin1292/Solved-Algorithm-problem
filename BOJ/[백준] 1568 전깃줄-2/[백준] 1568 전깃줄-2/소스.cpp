#include <iostream>
#include <map>
#include <vector>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> lines;

map<int, int> a_to_b; // a_to_b[9] = 7
map<int, int> b_to_a; // b_to_a[7] = 9 

map<int, bool> connections; // connections[i] = true -> 연결유지

vector < pair<int, int> > arr; // {원본 배열 값, LIS에서 인덱스 }
// 추적 가능하게 만들 것 !

void lis() {
	vector<int> vec;
	vec.push_back(lines[0]);
	arr.push_back({ lines[0], 0 });
	for (int i = 1; i < lines.size(); i++) {
		int k = lines[i];
		if (vec.back() >= k) {
			auto lowerBound = lower_bound(vec.begin(), vec.end(), k);
			*lowerBound = k;
			int idx = lowerBound - vec.begin();
			arr.push_back({ k,idx });
		}
		else {
			vec.push_back(k);
			arr.push_back({ k, vec.size() - 1 });
		}
	}


	int count = vec.size() - 1;
	for (int i = arr.size() - 1; i >= 0; i--) {
		if (arr[i].second == count) {
			connections[b_to_a[arr[i].first]] = true;
			count--;
		}
	}

	cout << lines.size() - vec.size() << "\n";

	for (auto connection : connections) {
		if (connection.second == false)
			cout << connection.first << "\n";
	}

}

int main() {

	fastio;
	int N;
	cin >> N;


	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		a_to_b[a] = b;
		b_to_a[b] = a;
		connections[a] = false;
	}

	int size = 0;
	for (auto m : a_to_b) {
		lines.push_back(m.second);
	}

	lis();

	return 0;
}