#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(string id) {
	int size = id.size();

	if (size < 3 || size >15)
		return false;

	if (id[0] == '.' || id[size - 1] == '.')
		return false;

	for (int i = 0; i < size ; i++) {
		if (id[i] == '-' || id[i] == '_')
			continue;
		else if ('a' <= id[i] && id[i] <= 'z')
			continue;
		else if ('0' <= id[i] && id[i] <= '9')
			continue;
		else if (id[i] == '.' && (i + 1 < size) && id[i + 1] == '.')
			return false;
		else
			return false;

	}

	return true;
}


string deleteAll(string id) {
	string temp;
	for (int i = 0; i < id.size(); i++) {
		if ('A' <= id[i] && id[i] <= 'Z')
			temp.insert(temp.end(), id[i] - ('A' - 'a'));
		if ('a' <= id[i] && id[i] <= 'z')
			temp.insert(temp.end(), id[i]);
		if ('0' <= id[i] && id[i] <= '9')
			temp.insert(temp.end(), id[i]);
		if (id[i] == '-' || id[i] == '_' || id[i] == '.')
			temp.insert(temp.end(), id[i]);
	}


	return temp;
}

string deleteDot(string id) {
	string temp = id;

	//두개이면 하나 지우기
	for (string::iterator i = temp.begin(); i!=temp.end() ; i++) {
		if (*i == '.' && i + 1 != temp.end() && *(i + 1) == '.') {
			temp.erase(i);
			i--;
		}
	}
	cout << "a " << temp << endl;
	if (temp[temp.size() - 1] == '.')
		temp = temp.substr(0, temp.size() - 1);
	if (temp[0] == '.')
		temp.erase(temp.begin());

	return temp;
}
string change(string id) {
	string temp;

	temp = deleteAll(id);
	temp = deleteDot(temp);

	if (temp.size() == 0)
		temp.insert(temp.end(), 'a');

	if (temp.size() > 15) {
		temp = temp.substr(0, 15);
		if (temp[temp.size() - 1] == '.')
			temp.pop_back();
	}


	char a = temp.back();
	while (temp.size() <= 2) {
		temp.insert(temp.end(), a);
	}

	return temp;
}


string solution(string new_id) {
	string answer = "";

	if (check(new_id))
		return new_id;
	else {
		return change(new_id);
	}

	return answer;
}
int main() {

	cout << "answer " << solution("z-+.^.");

}