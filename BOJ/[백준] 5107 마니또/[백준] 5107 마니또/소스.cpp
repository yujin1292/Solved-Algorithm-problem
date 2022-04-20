#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>


using namespace std;

bool visited[21];
vector<int> g[21];
map<string, int> nameToNum;

int main() {

	int friends, testCase = 1;

	while (true) {
		cin >> friends;
		if (friends == 0) break;

		//초기화
		nameToNum.clear();
		for (int i = 0; i < friends; i++) {
			visited[i] = false;
			g[i].clear();
		}

		// 입력
		for( int i = 0 ; i < friends ; i++) {
			string from, to;
			cin >> from >> to;

			if (nameToNum.find(from) == nameToNum.end()) 
				nameToNum[from] = nameToNum.size();
			
			if (nameToNum.find(to) == nameToNum.end()) 
				nameToNum[to] = nameToNum.size();
			
			g[nameToNum[from]].push_back(nameToNum[to]);
		}
		


		int answer = 0;
		for (int i = 0; i < friends; i++) {
			if (visited[i]) continue;
			answer++;
			visited[i] = true;
			queue<int> q;
			q.push(i);

			// bfs
			while (!q.empty()) {
				int front = q.front();
				q.pop();

				for (int next : g[front]) {
					if (visited[next]) continue;
					visited[next] = 1;
					q.push(next);
				}
			}
		}

		cout << testCase << " " << answer << "\n";
		testCase++;
	}

	return 0;
}