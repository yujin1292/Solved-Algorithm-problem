#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<string , greater<string> > s;
vector<pair<int, int> > countInter;

vector<string> parsing(string ss) {

	vector<string> result;
	string temp;

	for (int i = 0; i < ss.size(); i++) {

		if ('a' <= ss[i] && ss[i] <= 'z') {
			temp.push_back(ss[i]);
		}
		else if ('A' <= ss[i] && ss[i] <= 'Z') 
			temp.push_back(ss[i] - ('A' - 'a'));
		else {
			temp.clear();
			continue;
		}

			

		if (temp.size() == 2) {
			result.push_back(temp);
			temp.clear();
			i--;
		}
	}

	return result;
}

bool isIn(vector<string> v, string ss) {
	vector<string> ::iterator iter;

	for (iter = v.begin(); iter != v.end(); iter++) {
		if (*iter == ss)
			return true;
	}

	return false;
}

int countNum(vector<string> a, string st) {
	int n = 0;
	
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == st)
			n++;
	}

	return n;
}

int interSection(vector<string> a, vector<string> b) {
	int count = 0;
	vector<pair<int, int> > countInter;

	set<string, greater<string> > ::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		int aa = countNum(a, *iter);
		int bb = countNum(b, *iter);
		countInter.push_back( make_pair(aa,bb)  );
		
	}

	for (int i = 0; i < countInter.size(); i++) {
		count += countInter[i].first < countInter[i].second ? countInter[i].first : countInter[i].second;
	}

	return count;
}



void goUinon(vector<string> a, vector<string> b) {
	for (int i = 0; i < a.size(); i++)
		s.insert(a[i]);
	for (int i = 0; i < b.size(); i++)
		s.insert(b[i]);
}

int solution(string str1, string str2) {
	int answer = 0;
	double temp = 1;

	vector<string> tokens1 = parsing(str1);
	vector<string> tokens2 = parsing(str2);

	if (tokens1.empty() && tokens2.empty())
		temp = 65536;
	else {

		goUinon(tokens1, tokens2);
		int inter_num = interSection(tokens1, tokens2);
		int union_num = tokens1.size() + tokens2.size() - inter_num;

		cout << "ÇÕ " << union_num << endl;
		cout << "±³ " << inter_num << endl;

		temp = inter_num * 65536 / union_num;
		

	}

	for (int i = 0; i < tokens1.size(); i++) {
		cout << tokens1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < tokens2.size(); i++) {
		cout << tokens2[i] << " ";
	}
	cout << endl;


	

	answer = temp;

	return answer;
}

int main() {

	cout << solution("eeeeaaaa","eeeeee");
}