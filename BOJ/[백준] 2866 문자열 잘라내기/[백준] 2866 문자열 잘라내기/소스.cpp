#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int r, c;

vector<string> inputs;
vector<string> cols;

bool isDebug = false;

int main() {

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		inputs.push_back(s);
	}

	for (int i = 0; i < c; i++) {
		string temp = "";
		for (int j = 0; j < r; j++) {
			temp += inputs[j][i];
		}

		cols.push_back(temp);
	}


	int count = 0;
	int deleted = 1; // 이 부분을 이분탐색으로 진행할수 있을듯함
	set<string> s;
	bool working = true;
	while (working) {
		s.clear();
		for (string col : cols) {
			string temp = col.substr(deleted, r - deleted);

			if(isDebug) cout << temp ;
			if (!s.empty() && s.find(temp) != s.end()) {
				working = false; 
				if (isDebug) cout << " finish" << endl;
				break;
			}
			else {
				s.insert(temp);
				if (isDebug) cout << " insert! " << endl;
			}
		}
		if (working) {
			count++;
			deleted++;
		}
		if (isDebug) cout << endl;
	}

	cout << count << endl;
	return 0;
}