#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int > b) {
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int> > v;


	int N, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back({temp, i});
	}


	sort(v.begin(), v.end());

	int last =  -1;
	int count = -1;
	for (int i = 0; i < N; i++) {
		
		if (last != v[i].first)
			count++;
		last = v[i].first;
		v[i].first = count;
	}

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " ;
	}

	return 0;
}