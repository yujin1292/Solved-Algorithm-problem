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
		//���������ִ� ī�� ������
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}

	cout << cards.front();

	return 0;
}