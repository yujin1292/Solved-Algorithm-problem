#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<char> numbers;

char digit2char(int num) {
	if (num < 10)
		return '0' + num;
	else
		return 'A' + (num - 10);
}

stack<char> to_n_digit(int num, int n) {
	int i = num;
	stack<char> digit;
	if (i == 0)
		digit.push('0');

	while (i) {
		digit.push( digit2char( i%n ));
		i /= n;
	}
	return digit;
}

void attach(int num,int n) {
	stack<char> temp = to_n_digit(num, n);
	//cout << num << "->";
	while (!temp.empty()) {
		numbers.push_back(temp.top());
	//	cout << temp.top() << " ";
		temp.pop();
	}

	//cout << endl;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	int total = m*(t-1) + p ;
	int i = 0;
	
	//원하는 순서알만큼 숫자 계산
	while (total > numbers.size()) {
		attach(i, n);
		i++;
	}

	//cout << total << endl;
	//cout << numbers.size();

	int index;
	//튜브차례 번호 알려주기
	for (int j = 0; j < t; j++) {
		//cout << j << endl;
		index = (p - 1) + m * j;
		answer.insert(answer.end(),numbers[index]);
	}

	return answer;
}

int main() {

	cout << solution(2, 4, 2, 1);
}