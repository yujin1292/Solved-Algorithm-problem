#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	map<string, string> pwd;
	string site, password;

	for (int i = 0; i < N; i++) {
		cin >> site >> password;
		pwd.insert(make_pair(site, password));
	}

	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << pwd[site] << "\n";
	}

	map<string, string>::iterator iter;
	for (iter = pwd.begin(); iter != pwd.end(); iter++) {
		cout << iter->first << " , " << iter->second << endl;
	}

	vector<int> v = { 1,2,43,5,6 };
	vector<int>::iterator i;

	for (i = v.begin(); i != v.end(); i++) {
		cout << *i << endl;
	}

	
	return 0;
}