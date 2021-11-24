#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iostream>

using namespace std;


vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	
	map<string , int>  m;

	for (int o = 0; o < orders.size() ; o++) {
	
		sort(orders[o].begin(), orders[o].end());

		for (int i = 0; i < pow(2, orders[o].size()); i++) {
			int t = 1;
			string temp = "";

			for (int j = 0; j < orders[o].size(); j++) {
				if (i & t) 
					temp.insert(temp.end(), orders[o][j]);

				t *= 2;
			}
			m[temp]++;
		}
	}

	map<string, int>::iterator iter;

	for (int i = 0; i < course.size(); i++) {
		int max = 0;
		for (iter = m.begin(); iter != m.end(); iter++) 
			if ((*iter).first.size() == course[i]) 
				if (max < (*iter).second)
					max = (*iter).second;
		if (max < 2)
			continue;
		for (iter = m.begin(); iter != m.end(); iter++)
			if ((*iter).first.size() == course[i])
				if (max == (*iter).second)
					answer.push_back( (*iter).first);
	}

	sort(answer.begin(), answer.end());
	return answer;
}

int main() {

	vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
	vector<int> c = { 2,3,4 };
	solution(orders, c);
}