#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(vector<int> a, vector<int> b) {
	return a.size() < b.size();
}
vector<int> solution(string s) {
	vector<int> answer;

	vector< vector<int> > set;
	vector<int> temp;

	int index = 0;
	int number = 0;

	for (int i = 0; i < s.length()-1; i++) {

		if (s[i] == '{') {
			continue;
		}

		else if (s[i] == '}') {
			set.push_back(temp);
			temp.clear();

			if (i + 1 < s.length()) {
				if (s[i + 1] == ',')
					i++;
			}
		}
		else if (s[i] == ',') {
			temp.push_back(number);
			number = 0;

		}
		else {
			number *= 10;
			number += (s[i] - '0');

			if (i + 1 < s.length()) {
				if (s[i + 1] == '}') {

					temp.push_back(number);
					number = 0;
				}
			}
		}

	}



	index--;

	sort(set.begin(), set.end(), cmp);


	answer.push_back(set[0][0]);
	for (int i = 1; i < set.size(); i++) {

		for (int j = 0; j < set[i].size(); j++) {

			int k;
			for (k = 0; k < answer.size(); k++) {
				if (answer[k] == set[i][j])
					break;
			}
			if( k == answer.size())
				answer.push_back(set[i][j]);

		}
	}


	return answer;
}
