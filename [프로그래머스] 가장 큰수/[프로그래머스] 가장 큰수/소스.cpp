#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#include <iostream>
using namespace std;

string solution(vector<int> numbers) {

	string answer = "";
	long long  max_num = -1;
	sort(numbers.begin(), numbers.end());

	do {
		string a = "";
		for (int i = 0; i < numbers.size(); i++) {
			a += to_string(numbers[i]);
		}

		long long  num = stoll(a);
		cout << a;
		if (max_num < num) {
			max_num = num;
		}
		cout<< endl;
	} while (next_permutation(numbers.begin(), numbers.end()));

	answer = to_string(max_num);

	return answer;
}

int main() {

	cout << solution({ 6,123,444,534 }) << endl;
	return 0;
}