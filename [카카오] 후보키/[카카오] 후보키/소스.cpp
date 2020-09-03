#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int visit[8]; //1개부터 8개까지
set<int> keys;
vector<int> keys2;

int attribute;
int tuples;
int numOfKey = 0;
vector<vector<string>> relation_;

bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b) {
	return a.first < b.first;
}

vector<int> toBinary(int i) {

	vector<int> choose;

	int num = i;
	vector<int> ss;
	while (num) {
		ss.push_back(num % 2);
		num /= 2;
	}

	for (int j = 0; j < attribute - ss.size(); j++)
		choose.push_back(0);
	for (int j = ss.size() - 1; j >= 0; j--)
		choose.push_back(ss[j]);


	return choose;
}

int toNumber(vector<int>a) {
	int result = 0;

	for (int i = 0; i < a.size(); i++) {
		result *= 2;
		result += a[i];
	}
	return result;
}

int One(int i) {
	int count = 0;
	vector<int> t= toBinary(i);
	for (int i = 0; i < t.size(); i++)
		if (t[i] == 1) count++;
	return count;
}

void print(int i) {
	int num = i;
	vector<int> ss;

	while (num) {
		ss.push_back(num % 2);
		num /= 2;
	}


	for (int j = 0; j < attribute - ss.size(); j++)
		cout << 0 << " ";
	for (int j = ss.size() - 1; j >= 0; j--)
		cout << ss[j] << " ";
	cout << endl;

}

bool isCandidateKey(int i) {
	set<vector<string>> s;

	// i 는 2진수
	// ex)  1 0 0 0  --> 1번째 속성선택

	vector<int> choose = toBinary(i);
	
	for (int ii = 0; ii < tuples; ii++) {
		vector<string> temp;
		for (int j = 0; j < attribute; j++) {
			if (choose[j] == 1)
				temp.push_back(relation_[ii][j]);
		}

		if (s.count(temp) != 0)
			return false;
		s.insert(temp);
	}

	return true;
}

int solution(vector<vector<string>> relation) {
	numOfKey = 0;

	relation_ = relation;
	attribute = relation[0].size();
	tuples = relation.size();
	int caseOfkeys = pow(2, attribute);

	vector<int> keys;
	bool cant;

	vector< pair<int, vector<int> > > numbers;


	// 선택할 속성 2진수로 표현 후 선택개수에따라서 정렬
	for (int i = 0; i < pow (2, attribute); i++) 
		numbers.push_back({ One(i) ,toBinary(i) });
	sort(numbers.begin(), numbers.end() , cmp);

	for (int i = 0; i <numbers.size() ; i++) {
		int num = toNumber(numbers[i].second);
		cant = false;

		for (int j = 0; j < keys.size(); j++) 
			if ( ( num & keys[j] )  == keys[j]) // 선택한 속성이 이미 후보키에 속한다
				cant = true;
		
		if (cant)
			continue;

		if (isCandidateKey(num)) {
			keys.push_back(num);
			numOfKey++;
		}
	}

	return numOfKey;
}


int main() {
	vector<vector<string>> temp = {
		{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},
		{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}
	};

	cout << solution(temp);

}