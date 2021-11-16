#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cards;

int find(int start, int end, int num) {
	int mid = (start + end) / 2;
	if (start > end) {
		return 0;
	}

	if (cards[mid] == num) return 1;
	else if (cards[mid] < num)
		return find(mid + 1, end, num);
	else
		return find(start, mid - 1, num);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, temp;
	cin >> N;
	for(int i = 0 ; i < N ; i++ ) {
		cin >> temp;
		cards.push_back(temp);
	}

	sort(cards.begin(), cards.end());

	cin >> M;
	for(int i = 0 ; i < M ; i++) {
		cin >> temp;
		cout << find(0, N - 1, temp) << " ";	
	}
	return 0;
}