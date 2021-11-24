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

int find(string msg) { // w�� ���� ������
	int j;
	string w;
	int size = msg.size();

	for (j = 1; j <= size; j++) { // j�� ���ڿ� ����
		w = msg.substr(0, j);

		if (j == size)   // �������� ������������ wã������
			return j;

		//�������� ������ ���ڿ� Ȯ��
		string temp = msg.substr(0, j + 1);
		if (dictionary.count(temp) == 0)  // ���� ���ڿ��� �ʸ� �׷��� ������ w!
			return j;
		else
			continue;

	}
	return -1;

}
void solve(string msg) { //��������� ã��
	if (msg.size() == 0)
		return;
	cout << msg << endl;
	int len = find(msg); //w�� ����

	answer.push_back(dictionary[msg.substr(0, len)]);
	cout << "--> " << msg.substr(0, len) << " ," << dictionary[msg.substr(0, len)] << endl;

	if (msg.size() > len) //�������� ��������
		dictionary.insert({ msg.substr(0,len + 1), dictionary.size() + 1 });

	solve(msg.substr(len, msg.size() - len));

}
vector<int> solution(string msg) {

	string w;
	int i, j;
	int size = msg.size();

	init(); //���� �ʱ�ȭ

	solve(msg);

	return answer;
}

int main() {
	
	solution("KAKAO");

}