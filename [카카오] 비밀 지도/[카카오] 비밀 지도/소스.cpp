#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;



string Decode(int n , int digit) {
	string temp;

	int num = n;
	stack<int> s;
	while (num) {
		s.push(num % 2);
		num /= 2;
	}

	for (int i = 0; i < digit - s.size(); i++) {
		temp.append("0");
	}

	while (!s.empty()) {
		if (s.top() == 0) {
			temp.append("0");
		}
		else {
			temp.append("1");
		}
		s.pop();
	}

	return temp;
}

string toMap (string number) {
	string temp = "";
	int size = number.size();
	for (int i = 0; i < size; i++) {
		if (number[i] == '0')
			temp.append(" ");
		else
			temp.append("#");
	}
	return temp;
}


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;


	for (int i = 0; i < n; i++)	{
		int val = arr1[i] | arr2[i];
		string temp = Decode(val, n);

		temp = toMap(temp);
		answer.push_back(temp);
	}


	return answer;
}

int main() {

	vector<int> arr1 = { 9, 20, 28, 18, 11 };
	vector<int> arr2 = { 30, 1, 21, 17, 28 };

	vector<string> temp = solution(5, arr1, arr2);

	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << endl;
	}
}