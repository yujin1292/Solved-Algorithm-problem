#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	pair<int, int> p;
	vector<pair<int, int> > v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p.first >> p.second;
		v.push_back(p);
	}

	sort(v.begin(), v.end(),cmp);


	for (int i = 0; i < N; i++) 
		cout << v[i].first << " " << v[i].second << "\n";

	return 0;
}