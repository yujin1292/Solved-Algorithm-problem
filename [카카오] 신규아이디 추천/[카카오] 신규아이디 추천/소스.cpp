#include <string>
#include <vector>
#include <iostream>

using namespace std;





string solution(string new_id) {
	string answer = "";
	string step1 = "";

	for (int i = 0; i < new_id.size(); i++) {
		if ('A' <= new_id[i] && new_id[i] <= 'Z')
			step1 += (new_id[i] - ('A' - 'a'));
		else
			step1 += new_id[i];
	}

	cout << "1  : " << step1 << endl;

	string step2 = "";
	for (int i = 0; i < step1.size(); i++) {
		if (step1[i] == '.')
			step2 += step1[i];
		else if (step1[i] == '-')
			step2 += step1[i];
		else if (step1[i] == '_')
			step2 += step1[i];
		else if ('0' <= step1[i] && step1[i] <= '9')
			step2 += step1[i];
		else if ('a' <= step1[i] && step1[i] <= 'z')
			step2 += step1[i];

	}
	cout << "2  : " << step2 << endl;

	string step3 = "";
	for (int i = 0; i < step2.size(); i++) {
		step3 += step2[i];
		if (step2[i] == '.') {
			int j;
			for (j = i + 1; j < step2.size(); j++) {
				if (step2[j] != '.') {
					i = (j - 1);
					break;
				}
			}
			if (j == step2.size())
				break;
		}
	}
	cout << "3  : " << step3 << endl;

	string step4 = "";
	if (step3.size() != 0 && step3.back() == '.')
		step4 = step3.substr(0, step3.size() - 1);
	else
		step4 = step3;

	if (step4.size() != 0 && step4.front() == '.')
		step4 = step4.substr(1);


	cout << "4  : " << step4 << endl;


	string step5 = "";

	if (step4.size() == 0)
		step5 = "a";
	else
		step5 = step4;



	cout << "5  : " << step5 << endl;

	string step6 = step5;
	if (step5.size() >= 15) {
		step6 = step5.substr(0, 15);
		if (step6.back() == '.')
			step6 = step6.substr(0, step6.size() - 1);
	}

	cout << "6  : " << step6 << endl;

	answer = step6;
	char temp = answer.back();
	if (step6.size() <= 2) {
		for (int i = 0; i < 3 - step6.size(); i++)
			answer += temp;
	}

	cout << "--> " << answer << endl;

	return answer;
}

int main() {
	
	cout << "...!@BaT#*..y.abcdefghijklm" << endl;

	solution("...!@BaT#*..y.abcdefghijklm");

	return 0;
}
