#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {

	int N;
	deque<int> cards;
	vector<int> skillSet;
	
	cin >> N;

	int skill;
	for (int i = 0; i < N; i++) {
		cin >> skill;
		skillSet.push_back(skill);
	}

	for (int i = 1; i <= N; i++) {
		skill = skillSet[N-i];
		// 아래 = back  위 = front
		if (skill == 1) {
			// 카드를 맨 윗장으로 돌려놓기
			cards.push_front(i);
		}
		else if (skill == 2) {
			// 카드를 위에서 두번째 자리에 넣기
			int temp = cards.front();
			cards.pop_front();
			cards.push_front(i);
			cards.push_front(temp);
		}
		else if (skill == 3) {

			cards.push_back(i);
		}
	}

	for (auto c : cards) {
		cout << c << " ";
	}

	return 0;
}