#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;


pair<string, string> split(string p) {
	pair<string, string> ans;


	int left = 0;
	int right = 0;
	int i;

	for ( i = 0; i < p.size(); i++) {
		if (p[i] == '(')
			left++;

		else if (p[i] == ')')
			right++;

		if (right == left) //±ÕÇüÀâÇûÀ½
			break;
		
	}

	ans.first = p.substr(0, i+1);
	
	if (i == p.size() - 1)
		ans.second = "";
	else
		ans.second = p.substr(i+1, p.size()-i);

	cout << ans.first << " " << ans.second << endl;
	return ans;
}

string reverse(string t) {
	string p = t;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(')
			p[i] = ')';

		else if (p[i] == ')')
			p[i] = '(';
	}
	return p;
}

bool isRight(string p) {
	int size = p.size();
	stack<char> s;
	if (size == 0)
		return true;


	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') 
			s.push('(');
		
		else if (p[i] == ')') {
			if (s.empty())
				return false;
			s.pop();
		}
	}

	if (s.empty())
		return true;
	else
		return false;

}


string solution(string p) {
	string answer = "";
	pair<string, string> temp;
	string u, v;

	if (isRight(p))
		return p;

	if (p == "")
		return "";

	temp = split(p);
	u = temp.first;
	v = temp.second;

	if (isRight(u)) {
		v = solution(v);
		answer = u + v;
	}
	else {
		answer = "(";
		v = solution(v);
		answer += v;
		answer.push_back(')');

		u = reverse(u.substr(1, u.size() - 2));

		answer += u;
	}



	return answer;
}




