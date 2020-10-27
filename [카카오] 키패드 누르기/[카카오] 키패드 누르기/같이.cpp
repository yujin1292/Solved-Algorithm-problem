#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int distance(int a, int middle) {
	int xa = ((a - 1) / 3) + 1;
	int xm = ((middle - 1) / 3) + 1;

	int ya = a % 3 == 0 ? 3 : a % 3;
	int ym = middle % 3 == 0 ? 3 : middle % 3;

	return abs(xa - xm) + abs(ya - ym);
}

string whatHand(int left, int right, int num, string hand) {

	//number가 왼손으로누르는 번호인가?
	if (num == 1 || num == 4 || num == 7 || num == 10)
		return "L";
	//number가 오른손으로 누르는 번호
	else if (num == 3 || num == 6 || num == 9 || num == 12)
		return "R";
	
	//가운데번호일때 --> 거리계산

	int leftD = distance(left, num);
	int rightD = distance(right, num);
	
	if (leftD == rightD)
		return hand;
	else if (leftD < rightD) return"L";
	else return "R";

}

string solution(vector<int> numbers, string hand) {
	string answer = "";  // L R로 구성되게


	int left = 10;
	int right = 12;

	string hand_ = (hand == "right") ? "R" : "L";
	for (int i = 0; i < numbers.size(); i++) {
		answer.append(whatHand(left, right, numbers[i], hand_));
	}
}
