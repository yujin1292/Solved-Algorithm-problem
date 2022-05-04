#include <iostream>
#include <string>

using namespace std;

int solve() {
	string str;
	cin >> str;

	// 문자열 길이 만큼 반복 검사!
	int answer = 0; 
	string cur = ""; 
	string pre = ""; 

	for (int i = 0; i < str.length(); i++) {
		cur += str[i];
		if (cur != pre) {
			answer++; 

			pre = cur; 
			cur = "";
		}
	}


	return answer;
}


int main() {

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		cout << "#" << t << " " << solve();
	}

	return 0;
}