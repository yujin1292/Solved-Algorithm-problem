#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n, m, temp, result = 987654321;
vector<vector<int>>ret;
vector<pair<int, int>> _home, chicken;
void combi(int start, vector<int> v) {
	if (v.size() == m) {
		ret.push_back(v);
		return;
	}
	for (int i = start + 1; i < chicken.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp == 1)_home.push_back({ i, j });
			if (temp == 2)chicken.push_back({ i, j });
		}
	}
	vector<int> v;
	combi(-1, v); //M∞≥ º±≈√

	for (vector<int> _ret : ret) { 
		int __ret = 0;
		for (pair<int, int> home : _home) {
			int _min = 987654321;
			for (int ch : _ret) {
				int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
				_min = min(_min, _dist);
			}
			__ret += _min;
		}
		result = min(result, __ret);
	}
	cout << result << "\n";
	return 0;
}