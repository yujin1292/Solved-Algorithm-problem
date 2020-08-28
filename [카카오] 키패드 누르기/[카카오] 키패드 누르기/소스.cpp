#include <string>
#include <vector>


using namespace std;
bool isLeft(int num) {
	return (num == 1 || num == 4 || num == 7 || num == 10);
}
bool isRight(int num) {
	return (num == 3 || num == 6 || num == 9 || num == 12);
}

int distance(int a, int middle) {

	int left_;
	int right_;
	int middle_ = (middle == 0) ? 11 : middle;
	int ans;



	if (isRight(a)) {
		right_ = a - 1;

		ans = middle_ < right_ ? right_ - middle_ : middle_ - right_;
		ans /= 3;
		ans++;
	}
	else if( isLeft(a) ){
		left_ = a + 1;
		ans = middle_ < left_ ? left_ - middle_ : middle_ - left_;
		ans /= 3;
		ans++;

	}
	else {

		right_ = a == 0 ? 11 : a;

		ans = middle_ < right_ ? right_ - middle_ : middle_ - right_;
		ans /= 3;
	}

	return ans;

}
string whatHand(int left, int right, int middle, string hand) {
	
	int distance_left;
	int distance_right;


	distance_left = distance(left, middle);
	distance_right = distance(right, middle);


	if (distance_left == distance_right) {
		if (hand == "right")
			return "R";
		else
			return "L";
	}
	else if (distance_left < distance_right) 
		return"L";
	
	else
		return "R";


}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	
	int left = 10;
	int right = 12;

	int size = numbers.size();
	for (int i = 0; i < size; i++) {
		if (isLeft(numbers[i])) {
			left = numbers[i];
			answer.append("L");
		}
		else if (isRight(numbers[i])) {
			right = numbers[i];
			answer.append("R");
		}
		else { //°¡¿îµ¥
			string temp;
			
			temp = whatHand(left, right, numbers[i], hand);
			answer.append(temp);
			if (temp == "R")
				right = numbers[i];
			else
				left = numbers[i];
				
		}

	}


	return answer;
}


