#include <iostream>
#include <queue>
using namespace std;


int main() {
	int N , temp;
	queue<int> cards;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cards.push(i);
	}

	while (cards.size() != 1) {
		//제일위에있는 카드 버리기
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}

	cout << cards.front();

	return 0;
}