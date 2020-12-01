#include <iostream>
#include <string>
#include <vector>

#define MAX 51

using namespace std;
int N, M;

vector<char> line1 = { 'B','W','B','W' ,'B','W' ,'B','W' };
vector<char> line2 = { 'W','B','W' ,'B','W' ,'B','W','B' };
vector<vector<char> > board1, board2;

int chess[MAX][MAX];

void init() {
	vector<vector<char> > lines;
	lines.push_back(line1);
	lines.push_back(line2);

	for (int i = 0; i < 8; i++) {
		board1.push_back(lines[i % 2]);
		board2.push_back(lines[1 - i % 2]);
	}

}

int checkBlock(int x, int y) {
	int case1, case2;
	case1 = case2 = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board1[i][j] != chess[x + i][y + j])
				case1++;
			if (board2[i][j] != chess[x + i][y + j])
				case2++;
		}
	}

	if (case1 < case2)
		return case1;
	else
		return case2;
}
int main() {

	init();
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
			chess[i][j] = s[j];
	}
	int result = 99999999;
	int temp;
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			temp = checkBlock(i, j);
			if (result > temp)
				result = temp;
		}
			
	}
	cout << result;
}