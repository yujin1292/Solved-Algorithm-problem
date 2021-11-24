#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int count_ = 0; // �̴µ� ���� ���� ȸ��
deque<int> numbers;

void pick(int num) {

	deque<int>::iterator iter = numbers.begin();
	int index = 0;

	while (iter != numbers.end()) { // ���� ����(num)�� ť������ ��ġ (index)  ã��
		if (*iter == num) {
			break;
		}
		iter++;
		index++;
	}

	// ���� { 1 2 3 4 5 6 7 8 9 }  �ε� 3�̸� �ε����� 2
	// �·� 2�� �����̱�(index��)  or ���������� 7�� �����̱� ( ťsize(9) - index(2)  �� ) 

	if (numbers.size() - index > index) { // �·� �����̱�

		for (int i = 0; i < index; i++) {
			numbers.push_back(numbers.front());
			numbers.pop_front();
		}
		count_ += index;
	}
	else { //��� �����̱�

		for (int i = 0; i < numbers.size() - index; i++) {
			numbers.push_front(numbers.back());
			numbers.pop_back();
		}
		count_ += numbers.size() - index;
	}

	//���� ��������ġ�� deque���� front���� ���ϴ� ���ڰ� ��ġ��! 
	numbers.pop_front(); //��ȣ �̱� 
}

int main() {

	int N; // ť�� ũ��
	int M; // �̾Ƴ����� �ϴ� ���� ���� 
	int temp;
	cin >> N >> M;

	// N��ŭ�� ���ڸ� deque�� �ְ� (�ʱ�ȭ) , ���ϴ� ������ ��ġ�� �ľ����� ����ȭ�� ������ ã�´�
	// ã�Ƴ� ������ ����(�ּڰ�)�� ���� count_�� ��� ������ ���Ѵ�. 

	for (int i = 1; i <= N; i++) { // dequeue �ʱ�ȭ
		numbers.push_back(i);
	}


	for (int i = 0; i < M; i++) {
		cin >> temp;
		pick(temp);
	} // M ��ŭ �̾Ƴ���

	cout << count_ << endl;

	return 0;
}