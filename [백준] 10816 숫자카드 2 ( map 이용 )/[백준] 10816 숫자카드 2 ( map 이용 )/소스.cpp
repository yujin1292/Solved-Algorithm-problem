#include <iostream>
#include <map>

using namespace std;

map<int, int> cards;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		cards[temp]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		cout << cards[temp] << " ";
	}
	return 0;
}