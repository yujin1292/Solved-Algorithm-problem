#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

deque<int> q;
string p;

bool isReversed = false;

void read(int n) {
	string t;
	cin >> t;
	int num = 0;
	for (int i = 1; i < t.size(); i++) {
		if (t[i] == ',' || t[i] == ']') {
			if(num!=0)
				q.push_back(num);
			num = 0;
		}
		else {
			num *= 10;
			num += (t[i] - '0');
		}	
	}
}

void print() {
	if (q.empty()) {
		cout << "[]\n";
		return;
	}

	if (isReversed) {
		cout << "[";
		for (int i = 1; i < q.size() ; i++) {
			cout << q[q.size() - i] << ",";
			
		}
		cout << q.front() << "]\n";

	}
	else {
		cout << "[";
		for (int i = 0; i < q.size() - 1; i++) {
			cout << q[i] << ",";
		
		}
		cout << q.back() << "]\n";
	}
}
void solve() {
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == 'R') { //뒤집기
			isReversed = !isReversed;
		}
		else if (p[i] == 'D') { //버리기
			if (q.empty()) {
				cout << "error\n";
				return;
			}
			
			if (isReversed)
				q.pop_back();
			else
				q.pop_front();
		}

	}
	print();
}


int main() {
	int T , n;

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> p;
		cin>> n;
		read(n);
		solve();
		q.clear();
		isReversed = false;
	}

	return 0;
}