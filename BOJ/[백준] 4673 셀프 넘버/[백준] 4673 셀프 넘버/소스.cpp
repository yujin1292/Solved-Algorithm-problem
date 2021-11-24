#include <iostream>

using namespace std;
int numbers[10000]; //생성되었는지 아닌지 확인할 배열
// 0이면 생성x 1이면 생성o

void checkSelfNumber(int num) {
	
	int number = num;

	int temp = num;

	while (temp != 0) {
		number += (temp % 10);
		temp /= 10;
	}


	//생성된 숫자 체크하기
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
