#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, int > names;

int main() {
	int N, M;
	string s;
	cin >> N >> M;
	for (int i = 0; i < N+M; i++) {
		cin >> s;
		names[s]++;
	}

	int count = 0;
	vector<string> temp;
	for (map<string,int>::iterator i = names.begin() ; i != names.end() ; i++) {
		if (i->second == 2) {
			temp.push_back( i->first);
			count++;
		}
	}

	cout << count << "\n";
	for (int i = 0; i < count; i++)
		cout << temp[i] << "\n";

	return 0;
}