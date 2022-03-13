#include <iostream>
#include <set>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

set<string> visited;
int dr[4] = { 0,0,-1,1 };
int dc[4] = { 1,-1,0,0 };


int main() {

	string temp;
	string s = "";

	int pos = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> temp;
			s.append(temp);
			if (temp == "0") {
				pos = i * 3 + j;
			}
		}
	}

	if (s == "123456780") {
		cout << 0 << endl;
		return 0;
	}

	queue<pair<string, int>> q;
	q.push({ s,pos });
	visited.insert(s);

	int count = 1;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			auto front = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nextRow = front.second / 3 + dr[i];
				int nextCol = front.second % 3 + dc[i];

				if (nextRow < 0 || nextRow >= 3) continue;
				if (nextCol < 0 || nextCol >= 3) continue;

				int nextPos = nextRow * 3 + nextCol;
				string next = front.first;
				next[front.second] = next[nextPos];
				next[nextPos] = '0';

				if (visited.count(next) > 0) continue;

				if (next == "123456780") {
					cout << count << endl;
					return 0;
				}

				visited.insert(next);
				q.push({ next, nextPos });
			}

		}
		count++;
	}

	cout << -1;

	return 0;
}