#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int num;
	set<int> s;


	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		s.insert(num);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		if (s.find(num) == s.end())
			cout << "0\n";
		else
			cout << "1\n";		
	}

	return 0;
}