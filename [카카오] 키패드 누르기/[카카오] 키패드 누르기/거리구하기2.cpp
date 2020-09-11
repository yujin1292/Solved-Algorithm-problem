#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;
bool isLeft(int num) {
	return (num == 1 || num == 4 || num == 7 || num == 10);
}
bool isRight(int num) {
	return (num == 3 || num == 6 || num == 9 || num == 12);
}
int distance(int a, int middle) {
	int xa = ((a - 1) / 3) + 1;
	int xm = ((middle - 1) / 3) + 1;

	int ya = a % 3 == 0 ? 3 : a % 3;
	int ym = middle % 3 == 0 ? 3 : middle % 3;

	return abs(xa - xm) + abs(ya - ym);
}
string whatHand(int left, int right, int middle, string hand) {
	int distance_left = distance(left, middle);
	int distance_right = distance(right, middle);

	if (distance_left == distance_right) return hand;
	else if (distance_left < distance_right) return"L";
	else return "R";
}

string solution(vector<int> numbers, string hand) {
	string answer = "";

	int left = 10;
	int right = 12;

	int size = numbers.size();
	int num;
	string temp;
	string hand_ = (hand == "right") ? "R" : "L";

	for (int i = 0; i < size; i++) {
		num = numbers[i] == 0 ? 11 : numbers[i]; //0 일떄 11로 바꿔주기
		if (isLeft(num)) {
			left = num;
			answer.append("L");
		}
		else if (isRight(num)) {
			right = num;
			answer.append("R");
		}
		else { //가운데
			temp = whatHand(left, right, num, hand_);
			answer.append(temp);
			if (temp == "R")
				right = num;
			else
				left = num;
		}

	}

	return answer;
}
