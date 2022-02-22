#include <iostream>

#define ll long long 
using namespace std;

int numberCount = -1;
int N;
ll result = -1;

void makeNumber(ll num, int digit) {

	if (digit == 0) {
		numberCount++;
		if (numberCount == N) result = num;
		//	cout << numberCount << ":  " << num << endl;
		return;
	}


	for (int i = digit - 1; i <= 9; i++) {
		if (num != 0 && num % 10 <= i) continue;
		ll nextNum = num * 10 + i;

		makeNumber(nextNum, digit - 1);
	}
}

int main() {

	cin >> N;

	// �������ִ� ����� ���� ���������� ���� ������ �������
	for (int i = 1; i <= 10; i++) {
		makeNumber(0, i);
	}

	cout << result << endl;

	return 0;
}