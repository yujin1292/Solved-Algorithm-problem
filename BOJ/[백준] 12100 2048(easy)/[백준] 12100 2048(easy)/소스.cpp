/*
* 참고
* https://katfun.tistory.com/entry/%EB%B0%B1%EC%A4%80-12100%EB%B2%88-2048-easy
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int n;
int answer = 0;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

vector<vector<int>> board;
vector<pair<int, int> > startPoint[4];

void move(int count, int dir, vector<vector<int>> board) {
	if (count == 5) return;
	
	vector<vector<int>> moved = board;

	int reversed;
	if (dir == 0) reversed = 1;
	else if (dir == 1) reversed = 0;
	else if (dir == 2) reversed = 3;
	else reversed = 2;

	stack<int> s;

	for (int i = 0; i < n; i++) {

		int row = startPoint[dir][i].first;
		int col = startPoint[dir][i].second;

		int repeat = n;
		while(repeat--){
			if (moved[row][col] != 0) s.push(moved[row][col]);
			moved[row][col] = 0;

			row += dr[dir];
			col += dc[dir];
		}


		// 합치고 합쳐진 값 차례대로 넣기 
		row = startPoint[reversed][i].first;
		col = startPoint[reversed][i].second;

		while (!s.empty()) {
			int first = s.top();
			s.pop();

			if (s.empty()) {
				if (answer < first) answer = first;
				moved[row][col] = first;
				row += dr[reversed];
				col += dc[reversed];
			}
			else {
				int second = s.top();
				s.pop();

				if (first == second) {
					if (answer < first+second) answer = first+second;
					moved[row][col] = first+second;
					row += dr[reversed];
					col += dc[reversed];
				}
				else {
					if (answer < first) answer = first;
					moved[row][col] = first;
					row += dr[reversed];
					col += dc[reversed];

					s.push(second);
				}
			}
		}
	
	}

	// 재귀적 접근
	for (int d = 0; d < 4; d++) {
		move(count+1, d, moved);
	}
}

int main() {
	cin >> n;

	// startPoint 초기화
	for (int dir = 0; dir < 4; dir++) {
		for (int i = 0; i < n; i++) {
			pair<int, int> point;
			if (dir == 0) point = { 0, i };
			else if (dir == 1) point = { n - 1, i };
			else if (dir == 2) point = { i, 0 };
			else point = { i, n - 1 };
		
			startPoint[dir].push_back(point);
		}
	}

	// 입력받기
	board = vector<vector<int> >(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (answer < board[i][j]) answer = board[i][j];
		}
	}

	// 함수 실행
	for (int dir = 0; dir < 4; dir++) {
		move(0, dir, board);
	}
	
	// 답 출력
	cout << answer << endl;
	return 0;
}