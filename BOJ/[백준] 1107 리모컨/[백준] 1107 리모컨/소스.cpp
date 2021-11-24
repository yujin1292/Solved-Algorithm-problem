#include <iostream>
#include <vector>
#include <string>

using namespace std;

int broken[10];
int dest;
vector<int> numbers;
int num;
bool print = false;
void makenumber(int digit, int count) {
	if (digit <= 0)
		return;
	if (count == digit) {
		numbers.push_back(num);
		if(print) cout << num << endl;
		return;
	}
	else if (count == 0  && digit != 1 ) { // 첫자리

		for (int i = 1; i < 10; i++) {

			if (broken[i])
				continue;

			num *= 10;
			num += (i);

			makenumber(digit, count + 1);
			num /= 10;
		}

	}
	else {

		for (int i = 0; i < 10; i++) {

			if (broken[i])
				continue;

			num *= 10;
			num += (i);

			makenumber(digit, count + 1);
			num /= 10;
		}

	}
}
void _makenumber() {
	string s_dest = to_string(dest);
	int digit = s_dest.size();
	
	makenumber(digit - 1, 0);
	if(print) cout << "-----------\n";
	makenumber(digit, 0);
	if(print) cout << "-----------\n";
	makenumber(digit + 1 ,0);
}

void solve() {
	int result = 999999;
	int temp , temp2;

	// CASE 1 
	// 100에서 시작 +- 로 조작하기
	
	temp = (dest > 100) ? dest - 100 : 100 - dest;
	
	if (temp < result)
		result = temp;

	// CASE 2
	// 숫자키 입력후 +- 로 조잘하기

	_makenumber();
	for (int i = 0; i < numbers.size(); i++) {
		
		temp = (dest > numbers[i]) ? dest - numbers[i] : numbers[i] - dest;
		temp += to_string(numbers[i]).size();

		if (temp < result)
			result = temp;
	}
	cout << result;
}

int main() {
	int nums, temp;
	cin >> dest;
	cin >> nums;
	for (int i = 0; i < nums; i++) {
		cin >> temp;
		broken[temp] = 1;
	}
	solve();
	return 0;
}