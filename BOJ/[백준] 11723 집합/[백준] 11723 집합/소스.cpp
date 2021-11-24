#include <iostream>
#include <string>

using namespace std;

int set[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string command;
		cin >> command;
		if (command == "add") {
			int num;
			cin >> num;
			if (set[num] == 0)
				set[num] = 1;
		}
		else if (command == "remove") {
			int num;
			cin >> num;
			set[num] = 0;
		}
		else if (command == "check") {
			int num;
			cin >> num;
			if (set[num] == 1)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (command == "toggle") {
			int num;
			cin >> num;
			set[num] = !set[num];				
		}
		else if (command == "all") {
			for (int i = 0; i < 21; i++)
				set[i] = 1;
		}
		else if (command == "empty") {
			for (int i = 0; i < 21; i++)
				set[i] = 0;
		}
	}
}