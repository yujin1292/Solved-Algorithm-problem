#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


int main() {

	string start, end, quit;
	string chat, id;

	cin >> start >> end >> quit;

	map<string, pair<int, int>> log;

	while (true) {
		cin >> chat >> id;

		if (chat <= start) {
			log[id].first = 1;
		}
		if (end <= chat && chat <= quit) {
			log[id].second = 1;
		}

		if (cin.eof() == true) break;
	}

	int result = 0;
	for (auto student : log) {
		if (student.second.first && student.second.second)
			result++;
	}
	cout << result << endl;


	return 0;
}