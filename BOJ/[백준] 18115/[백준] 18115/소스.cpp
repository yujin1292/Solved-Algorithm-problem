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
		// �Ʒ� = back  �� = front
		if (skill == 1) {
			// ī�带 �� �������� ��������
			cards.push_front(i);
		}
		else if (skill == 2) {
			// ī�带 ������ �ι�° �ڸ��� �ֱ�
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