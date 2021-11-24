#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> temp;
	vector<int>::iterator start, end;
	for (int i = 0; i < commands.size(); i++) {
		temp = array;
		start = temp.begin() + commands[i][0] -1;
		end = temp.begin() + commands[i][1]  ;
		sort(start, end);
		
		answer.push_back(*(start + commands[i][2] -1 ));
	}

	return answer;
}