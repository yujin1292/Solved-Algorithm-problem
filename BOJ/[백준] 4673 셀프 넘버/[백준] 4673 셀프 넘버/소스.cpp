#include <iostream>

using namespace std;
int numbers[10000]; //�����Ǿ����� �ƴ��� Ȯ���� �迭
// 0�̸� ����x 1�̸� ����o

void checkSelfNumber(int num) {
	
	int number = num;

	int temp = num;

	while (temp != 0) {
		number += (temp % 10);
		temp /= 10;
	}


	//������ ���� üũ�ϱ�
	if( number <= 10000)
		numbers[number-1] = 1;
}

int main() {
	int size = 10000;

	for (int i = 0; i < size; i++) {
		checkSelfNumber(i+1);
	}

	for (int i = 0; i < size; i++) {
		if (numbers[i] == 0)
			cout << i + 1 << "\n";
	}

	return 0;
}
