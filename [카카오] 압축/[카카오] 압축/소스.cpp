#include <string>
#include <vector>
#include <map>

#include <iostream>

using namespace std;

map<string, int> dictionary;
vector<int> answer;

void init() {
	char c = 'A';
	string temp;

	for (int i = 1; i<=26; i++) {
		temp.clear();
		temp.insert(temp.begin(), c);
		dictionary.insert({ temp, i });
		c++;
	}

}

int find(string msg) { // w의 길이 리턴함
	int j;
	string w;
	int size = msg.size();

	for (j = 1; j <= size; j++) { // j는 문자열 길이
		w = msg.substr(0, j);

		if (j == size)   // 다음글자 존재하지않음 w찾은것임
			return j;

		//다음글자 포함한 문자열 확인
		string temp = msg.substr(0, j + 1);
		if (dictionary.count(temp) == 0)  // 다음 문자열은 초면 그러면 지금이 w!
			return j;
		else
			continue;

	}
	return -1;

}
void solve(string msg) { //재귀적으로 찾기
	if (msg.size() == 0)
		return;
	cout << msg << endl;
	int len = find(msg); //w의 길이

	answer.push_back(dictionary[msg.substr(0, len)]);
	cout << "--> " << msg.substr(0, len) << " ," << dictionary[msg.substr(0, len)] << endl;

	if (msg.size() > len) //다음글자 남아있음
		dictionary.insert({ msg.substr(0,len + 1), dictionary.size() + 1 });

	solve(msg.substr(len, msg.size() - len));

}
vector<int> solution(string msg) {

	string w;
	int i, j;
	int size = msg.size();

	init(); //사전 초기화

	solve(msg);

	return answer;
}

int main() {
	
	solution("KAKAO");

}