#include <stack>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {

	deque<pair<char, int>> s;
	string str, bomb;

	cin >> str >> bomb;

	int idx = 0;
	int size = bomb.size();

	for (auto c : str) {
		if (c == bomb[idx]) {
			idx++;
			s.push_back(make_pair(c, idx));

			if (idx == size) {
				for (int i = 0; i < size; i++) 
					s.pop_back();

				if (s.empty()) idx = 0;				
				else idx = s.back().second;			
			}
		}
		else {
			idx = 0;
			if (c == bomb[idx]) idx++;

			s.push_back(make_pair(c, idx));
		}
	}

	if (s.empty()) cout << "FRULA";
	else for (auto c : s) cout << c.first;
	
	return 0;
}