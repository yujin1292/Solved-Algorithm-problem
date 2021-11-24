#include <iostream>
#include <map>
#include <string>

#define MAX 1000001

using namespace std;

int N, M;
string name[MAX];
map<string, int> name_m;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N>>M;
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		name[i] = temp;
		name_m.insert({ temp, i+1 });
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if ('A' <= temp[0] && temp[0] <= 'Z') {
			cout << name_m[temp] << "\n";
		}
		else {
			cout << name[stoi(temp)-1] << "\n";
		}
	}
	return 0;
}