#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int note[12]; // ����ġ�� �̵��� ����
int note2Int(string s) {

	if (s == "C")
		return 0;
	else if (s == "C#")
		return 1;
	else if (s == "D")
		return 2;
	else if (s == "D#")
		return 3;
	else if (s == "E")
		return 4;
	else if (s == "F")
		return 5;
	else if (s == "F#")
		return 6;
	else if (s == "G")
		return 7;
	else if (s == "G#")
		return 8;
	else if (s == "A")
		return 9;
	else if (s == "A#")
		return 10;
	else if (s == "B")
		return 11;

	return -1;
}
void init(vector<string> m) {

	for (int i = 0; i < 12; i++)
		note[i] = -1;

	//���̾�� ����
	int index = 0;
	for (int i = m.size() - 1; i >= 0; i--) {
		if (note[note2Int(m[i])] == -1) {
			note[note2Int(m[i])] = index;
			index++;
		}
	}
	for (int i = 0; i < 12; i++) {
		if (note[i] == -1)
			note[i] = m.size();
	}

}



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
		//���� �ð� üũ
		s.push_back(temp.substr(0, 2) + temp.substr(3, 2));
		//������ �ð� üũ
		s.push_back(temp.substr(6, 2) + temp.substr(9, 2));

		// ��ǥ ã�Ƽ� ����,  �Ǻ� üũ
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
	//���� ���� Ȯ��
	string start = info[0];
	string end = info[1];

	string sheet_ = info[3];
	vector<string> sheet = toMelody(sheet_);
	vector<string> ans;


	time = toMin(end) - toMin(start); //�� �÷��̽ð� min ����

	int j = 0;
	for (int i = 0; i < time; i++) {
		ans.push_back(sheet[j]);
		if (j == sheet.size() - 1)
			j = -1;
		j++;
	}
	return ans;

}
bool solve(vector<string> melody, vector<string> sheet) { //���ڿ� ��

	int msize = melody.size();
	int ssize = sheet.size();
	int gap;

	bool isOk;
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

void printV(vector<string> v) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	cout << endl;
}
bool solve2(vector<string> melody, vector<string> sheet) {
	
	int msize = melody.size();
	int ssize = sheet.size();
	int gap;
	bool check = false;
	for (int i = msize-1 ; i < ssize ; i++) {

	   //���ڸ� Ȯ��
	   if (sheet[i] != melody[msize - 1]) {
	       i += note[note2Int(sheet[i])]; //���� �ٸ��ϱ� �ǳʶٱ�
	       i--;
	       if (i > ssize)
	           return false;
	       continue;
	   }
	   else {
		   check = true;
		   //���ڸ��� ���� --> �񱳽���
		   for (int index = 0; index < msize; index++) {
			   if (sheet[i - index] != melody[msize - 1 - index]) { //�� ����
				   check = false;
				   break;
			   }
		   }
		   if (check)
			   return true; //�� ����! ��ġ
	   }
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

	//���� ó��
	vector<string> melody = toMelody(m);
	vector<vector<string> > info = toInfo(musicinfos);


	vector< pair< int, int > > right;

	/*
	���̾� ���� Ž������ --> ���ڿ��� ��� ȿ�����������ϴ�
		
		init(melody);
		for (int i = 0; i < info.size(); i++) {
			vector<string> sheet = toSheet(info[i]);
			if (solve2(melody, sheet))
				right.push_back({ i , toMin(info[i][1]) - toMin(info[i][0]) });
		}

	
	*/

	for (int i = 0; i < info.size(); i++) {
		vector<string> sheet = toSheet(info[i]);
		if (solve(melody, sheet))  // ������ 
			right.push_back({ i , toMin(info[i][1]) - toMin(info[i][0]) });
	}


	if (right.empty())
		answer = "(None)";
	else {
		//�ߺ����ǿ� ���缭 ������ ���
		sort(right.begin(), right.end(), cmp);
		answer = info[right.front().first][2];
	}

	return answer;
}

int main() {

	string m = "ABC";
	vector<string> musicinfos = { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" };

	cout << solution(m, musicinfos);

	return 0;
}