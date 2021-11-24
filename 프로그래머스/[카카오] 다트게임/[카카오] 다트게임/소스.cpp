#include <string>
#include <stack>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int number = 0;

	stack<int> ans;
	int size = dartResult.size();

	for (int i = 0; i < size; i++) {

		if (dartResult[i] == '*') {
			int one = ans.top();
			ans.pop();
			if (!ans.empty()) {
				int two = ans.top();
				ans.pop();
				ans.push(two * 2);
			}

			ans.push(one * 2);
		}
		else if (dartResult[i] == '#') {
			int one = ans.top();
			ans.pop();
			ans.push(one * -1);
		}
		else if (dartResult[i] == 'S') {
			ans.push(number);
			number = 0;
		}
		else if (dartResult[i] == 'D') {
			int num = number;
			ans.push(num*num);
			number = 0;
		}
		else if (dartResult[i] == 'T') {
			int num = number;
			ans.push(num*num*num);
			number = 0;
		}
		else { //¼ýÀÚ
			number *= 10;
			number += dartResult[i]-'0';

		}
	}


	while (!ans.empty()) {
		answer += ans.top();
		ans.pop();
	}



	return answer;
}


