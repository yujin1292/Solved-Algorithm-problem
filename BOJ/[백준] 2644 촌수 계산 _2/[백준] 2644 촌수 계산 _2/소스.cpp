#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visitB[101];
vector<int> j[101];


void solve(int a, int b) {
	int chon = 0;
	queue<int> q;
	
	q.push(a);
	visitB[a] = 1;

	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			
			if (q.front() == b) {
				cout << chon << endl;
				return;
			}
			for (int i = 0; i < j[q.front()].size(); i++) {
				if (visitB[j[q.front()][i]])
					continue;

				q.push(j[q.front()][i]);
				visitB[j[q.front()][i]] = 1;
			}
			q.pop();
		}

		chon++;

	}
	cout << -1 << endl;
}

int main() {
	int family, a, b, edge;

	cin >> family >> a >> b >> edge;

	int t1, t2;

	for (int i = 0; i < edge; i++) { // ют╥б
		cin >> t1 >> t2;

		j[t2].push_back(t1);
		j[t1].push_back(t2);

	}

	solve(a, b);


	return 0;
}