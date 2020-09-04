#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;


vector<string> toMelody(string m) {
	queue<int> sharp;
	vector<string> parse;

	for (int i = 0; i < m.size(); i++)
		if (m[i] == '#')
			sharp.push(i - 1);
	for (int i = 0; i < m.size(); i++) {
		if (!sharp.empty() && sharp.front() == i) {
			parse.push_back(m.substr(i, 2));
			i++;
			sharp.pop();
		}
		else
			parse.push_back(m.substr(i, 1));
	}

	return parse;
}
vector< vector<string> > toInfo(vector<string> info) {
	vector< vector<string> > result;
	// 00:00,00:00,~~ , ~~ 
	string temp;
	for (int i = 0; i < info.size(); i++) {
		vector<string> s;
		temp = info[i];
		//시작 시간 체크
		s.push_back(temp.substr(0, 2) + temp.substr(3, 2));
		//끝나는 시간 체크
		s.push_back(temp.substr(6, 2) + temp.substr(9, 2));

		// 쉼표 찾아서 제목,  악보 체크
		for (int j = 12; j < temp.size(); j++) {
			if (temp[j] == ',') {
				s.push_back(temp.substr(12, j - 12));
				s.push_back(temp.substr(j + 1, temp.size() - j));
				break;
			}
		}

		result.push_back(s);
	}
	return result;
}
int toMin(string s) {
	int hour = (s[0] - '0') * 10 + (s[1] - '0');
	int min = (s[2] - '0') * 10 + (s[3] - '0');
	return hour * 60 + min;
}
vector<string> toSheet(vector <string> info) {
	int hour, min, time;
	//음악 길이 확인
	string start = info[0];
	string end = info[1];

	string sheet_ = info[3];
	vector<string> sheet = toMelody(sheet_);
	vector<string> ans;


	time = toMin(end) - toMin(start); //총 플레이시간 min 단위

	int j = 0;
	for (int i = 0; i < time; i++) {
		ans.push_back(sheet[j]);
		if (j == sheet.size() - 1)
			j = -1;
		j++;
	}
	return ans;

}
bool solve(vector<string> melody, vector<string> sheet) { //문자열 비교

	int msize = melody.size();
	int ssize = sheet.size();
	int gap;

	bool isOk = false;
	for (int i = 0; i < ssize - msize + 1; i++) {
		isOk = true;
		for (int j = 0; j < msize; j++) {
			if (sheet[i + j] != melody[j])
				isOk = false;
		}
		if (isOk)
			return true;

	}

	return false;
}
bool cmp(pair< int, int > a, pair< int, int > b) {

	if (a.second == b.second)
		return a < b;
	else
		return b.second < a.second;
}



string solution(string m, vector<string> musicinfos) {
	string answer = "";

	//정보 처리
	vector<string> melody = toMelody(m);
	vector<vector<string> > info = toInfo(musicinfos);


	vector< pair< int, int > > right;
	// 문자열 탐색
	for (int i = 0; i < info.size(); i++) {
		vector<string> sheet = toSheet(info[i]);
		if (solve(melody, sheet))  // 정답임 
			right.push_back({ i , toMin(info[i][1]) - toMin(info[i][0]) });
	}


	if (right.empty())
		answer = "(None)";
	else {
		//중복조건
		sort(right.begin(), right.end(), cmp);
		answer = info[right.front().first][2];
	}

	return answer;
}

int main() {

	string m = "ABC#";
	vector<string> musicinfos = { "03:00,03:40,ONE,C#DAB", "04:00,05:40,TWO,FFFABC#FFF" };

	cout << solution(m, musicinfos);

	return 0;
}