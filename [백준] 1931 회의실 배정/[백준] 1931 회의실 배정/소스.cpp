#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 100001
using namespace std;
vector<pair<int, int> > meeting;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, start, end;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		meeting.push_back({ end, start });
	}
	sort(meeting.begin(), meeting.end());
	

	int count = 0;
	end = 0;
	for (int i = 0; i < N; i++) {
		if (end <= meeting[i].second) {
			end = meeting[i].first;
			count++;
		}
	}

	cout << count << endl;

	return 0;
}