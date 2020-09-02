#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>


using namespace std;
class statement;

vector<statement> orders;
map<string,string> users;

class statement {
public:

	string uid;
	string op;

	void set(string id, string opp) {
		
		op = opp;
		uid = id;
	}
	void printString() {
		cout << "[" << op << ")" << users[uid] << "," << uid << "]" << endl;
	}
	string getString() {

		string temp = users[uid];

		string e = "님이 들어왔습니다.";
		string l = "님이 나갔습니다.";

		if (op == "Enter")
			temp.append(e);
		else if (op == "Leave")
			temp.append(l);


		return temp;
	}
};

void parsing(string s) {

	statement temp;

	int i = 6;
	int index;
	string uid, name, op;

	if (s[0] == 'C') //Change
		i = 7;

	for (index = i; index < s.size(); index++)
		if (s[index] == ' ')
			break;

	op = s.substr(0, i - 1);
	uid = s.substr(i, index - i);
	
	if (s[0] != 'L')
		name = s.substr(index + 1, s.size() - index);
	else
		name = " ";

	// map 초기화 
	if (op == "Change"){
		users[uid] = name;
		return;
	}
	else if (op == "Enter") 
		users[uid] = name;
	

	temp.set(uid, op);
	orders.push_back(temp);
}

vector<string> GO() {
	vector<string> answer;

	for (int i = 0; i < orders.size(); i++) {
		//cout << orders[i].getString() << endl;
		answer.push_back(orders[i].getString());
	}
	return answer;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;

	for (int i = 0; i < record.size(); i++) {
		parsing(record[i]);
	}
	
	answer = GO();

	return answer;
}

int main() {

	vector<string> record = {
		"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234",
		"Enter uid1234 Prodo","Change uid4567 Ryan"
	};


	vector<string> result = solution(record);

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;

}