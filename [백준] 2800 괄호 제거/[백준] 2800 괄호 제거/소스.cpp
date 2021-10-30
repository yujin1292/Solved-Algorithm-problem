#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string s;
vector<string> answer;
vector<pair<int, int> > parenthesis;

void deleteParenthesis() {

	int max = pow(2, parenthesis.size());	
	for (int i = 1; i < max; i++) {
		int check = 1;
		string temp = "";
		vector<int> selected(s.size(),0);

		for (int bit = 0; bit < parenthesis.size(); bit++) {
			if (i & check) {
				selected[parenthesis[bit].first] = 1;
				selected[parenthesis[bit].second] = 1;
			}
			check *= 2;
		}

		for (int idx = 0; idx < s.size(); idx++) {
			if (selected[idx] == 0) {
				temp += s[idx];
			}
		}
		answer.push_back(temp);
	}
}

int main() {
	cin >> s;

	stack<int> index;
	int id = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			index.push(i);
		}
		else if (s[i] == ')') {
			id++;
			parenthesis.push_back(make_pair(i, index.top()));
			index.pop();
		}
	}

	deleteParenthesis();

	sort(answer.begin(), answer.end());
	auto ptr = unique(answer.begin(), answer.end());
	answer.erase(ptr, answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";

	return 0;
}