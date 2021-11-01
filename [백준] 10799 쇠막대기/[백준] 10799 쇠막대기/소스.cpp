#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 4ms 걸림 100배 빠르다
int main() {

	string line;
	cin >> line;

	stack<int> openIndex;
	int count = 0;

	for (int i = 0; i < line.size(); i++) {

		if (line[i] == '(') {
			openIndex.push(i);
			count++;
		}
		else {
			int idx = openIndex.top();
			openIndex.pop();
			//laser
			if (idx + 1 == i) {
				count--;
				count += openIndex.size();
			}
		}

	}

	cout << count;

	return 0;
}


/*
// 504 ms 걸림! 
int main() {

	string line;
	cin >> line;

	stack<int> openIndex;
	vector<int> lasers;
	vector< pair<int,int> > sticks; // (start, end);


	for (int i = 0; i < line.size(); i++) {
		
		if (line[i] == '(') {
			openIndex.push(i);
		}
		else {
			int idx = openIndex.top();
			openIndex.pop();
			
			//laser
			if (idx + 1 == i) lasers.push_back(idx);			
			else sticks.push_back(make_pair(idx, i));
		}

	}

	int count = sticks.size();

	for (auto stick : sticks) {
		for (auto laser : lasers) {
			if (stick.first <= laser && laser <= stick.second) {
				//cut
				count++;
			}
		}
	}

	cout << count;

	return 0;
}
 */