#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


const int MAX = 500 * 500 + 1;
int n, h, d, row, col, endRow, endCol;
int answer = MAX;

char map[500][500];
vector<pair<int, int> > umbrellas;
bool visited[11];


void dfs(int r, int c, int distance, int life, int umbrella) {

	// End point로 이동시도
	int distanceToEndPoint = abs(endRow - r) + abs(endCol - c);
	if (life + umbrella >= distanceToEndPoint)  {

		if (answer > distanceToEndPoint + distance) {
			answer = distanceToEndPoint + distance;
		}

		return;
	}
	

	// Unbrella로 이동 
	for (int i = 0; i < umbrellas.size(); i++) {
		if (visited[i]) continue;

		int distanceToUmbrella = abs(umbrellas[i].first - r) + abs(umbrellas[i].second - c);
		
		if (life + umbrella >= distanceToUmbrella) {
			int shielded = (distanceToUmbrella - umbrella) < 0 ? 0 : distanceToUmbrella - umbrella;
			int nextLife = life - shielded;

			visited[i] = true;
			dfs(umbrellas[i].first, umbrellas[i].second, distance + distanceToUmbrella ,nextLife, d);
			visited[i] = false;
		}
	}

}


int main() {
	string s;
	cin >> n >> h >> d;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
			if (s[j] == 'S') {
				row = i;
				col = j;
			}
			else if (s[j] == 'U') {
				umbrellas.push_back(make_pair(i, j));
			}
			else if (s[j] == 'E') {
				endRow = i;
				endCol = j;
			}
		}
	}

	dfs(row, col, 0, h, 0);

	if (answer == MAX) cout << "-1";
	else cout << answer;

	return 0;
}

