#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {

	int len = s.length();
	int answer = len;


	vector<string> tokens;

	for (int i = 1; i <= len; i++) {
		
		// i 개단위로 자르기
		string temp;
		for (int index = 0; index < len; index++) {
			temp.insert(temp.end(), s[index]);

			if ((index + 1) % i == 0) {
				tokens.push_back(temp);
				temp = "";
			}
		}
		if( temp != "")
			tokens.push_back(temp);

	
		int cal = 0;

		// 압축
		int num = 0;
		temp = tokens[0];
		for (int d = 0; d < tokens.size(); d++) {
			if (tokens[d] != temp) {
				
				if (num != 1)
					cal += to_string(num).size();
				cal += temp.size();

				num = 0;
				temp = tokens[d];		
			}
			num++;
		}
		if( num != 1)
			cal += to_string(num).size();
		cal += temp.size();



		tokens.clear();

		//최솟값 갱신
		if (answer > cal) {
			answer = cal;
		}

	}


	return answer;
}

