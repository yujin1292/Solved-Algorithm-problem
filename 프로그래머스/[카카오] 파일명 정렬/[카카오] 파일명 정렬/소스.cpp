#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class fileName {
public :
	string head;
	string head_;
	string number;
	string tail;

	int time;
	int number_;
	
	fileName(int tt, string h, string n, string t){
	
		time = tt;
		head = h;
		number = n;
		tail = t;

	
		number_ = stoi(n, 0, 10);
		head_ = h;
		transform(head_.begin(), head_.end(), head_.begin(), ::tolower);

	}

	string toString() {
		return head + number + tail;
	}
	
	bool isRight(fileName f) { //f�� �� ū��� true
	
		bool h, n;
		// head ������ ��
		h = head_ == f.head_;
		n = number_ == f.number_;

		if (h) {
			if (n) { //��� �ѹ�������� �ð�������
				return time < f.time;
			}
			return number_ < f.number_;
		}
		return head_ < f.head_;
	}
};

fileName parsing(int time, string f) {
	string head, number, tail;
	int i , j;
	for (i = 0 ; i < f.size(); i++) 
		if ('0' <= f[i] && f[i] <= '9')
			break;
	
	//i���� Number
	head = f.substr(0, i);

	for (j = i; j < f.size(); j++)
		if ( !( '0' <= f[j] && f[j] <= '9' ))
			break;
	//j���� tail
	number = f.substr(i, j - i);
	tail = f.substr(j, f.size() - j);
	
	return fileName(time, head, number, tail);
	
}

vector<string> solution(vector<string> files) {
	vector<string> answer;

	//������ ����
	vector<fileName> list;
	for (int i = 0; i < files.size(); i++) {
		list.push_back(parsing( i, files[i] ));
	}

	//����
	for (int i = 0; i < list.size()-1; i++) {
		for (int j = 0; j < list.size()-1-i; j++) {
			if (! list[j].isRight(list[j+1])) { //swap
				fileName temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
	for (int i = 0; i < list.size(); i++) {
		answer.push_back(list[i].toString());
	}
	

	return answer;
}

int main() {

	vector<string > input = {
		 "img12.png", "img10.png", "img02.png", "img1.png",
		 "IMG01.GIF", "img2.JPG"
	};
	
	vector<string> a = solution(input);
	for (int i = 0 ; i < a.size(); i++)
		cout << a[i] << endl;

}