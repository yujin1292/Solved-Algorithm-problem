#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int count_ = 0; // 뽑는데 사용된 연산 회수
deque<int> numbers;

void pick(int num) {

	deque<int>::iterator iter = numbers.begin();
	int index = 0;

	while (iter != numbers.end()) { // 뽑을 숫자(num)의 큐에서의 위치 (index)  찾기
		if (*iter == num) {
			break;
		}
		iter++;
		index++;
	}

	// 만약 { 1 2 3 4 5 6 7 8 9 }  인데 3이면 인덱스는 2
	// 좌로 2번 움직이기(index번)  or 오른쪽으로 7번 움직이기 ( 큐size(9) - index(2)  번 ) 

	if (numbers.size() - index > index) { // 좌로 움직이기

		for (int i = 0; i < index; i++) {
			numbers.push_back(numbers.front());
			numbers.pop_front();
		}
		count_ += index;
	}
	else { //우로 움직이기

		for (int i = 0; i < numbers.size() - index; i++) {
			numbers.push_front(numbers.back());
			numbers.pop_back();
		}
		count_ += numbers.size() - index;
	}

	//위의 연산을마치면 deque에의 front에는 원하는 숫자가 위치함! 
	numbers.pop_front(); //번호 뽑기 
}

int main() {

	int N; // 큐의 크기
	int M; // 뽑아내려고 하는 수의 개수 
	int temp;
	cin >> N >> M;

	// N만큼의 숫자를 deque에 넣고 (초기화) , 원하는 숫자의 위치를 파악한후 최적화된 연산을 찾는다
	// 찾아낸 최적의 연산(최솟값)의 수를 count_에 계속 누적해 더한다. 

	for (int i = 1; i <= N; i++) { // dequeue 초기화
		numbers.push_back(i);
	}


	for (int i = 0; i < M; i++) {
		cin >> temp;
		pick(temp);
	} // M 만큼 뽑아내기

	cout << count_ << endl;

	return 0;
}