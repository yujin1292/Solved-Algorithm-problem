#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int const MAX = 100;
int M[MAX][MAX];
int visit[MAX][MAX];

vector< pair<int, int> > matrix_;
deque< pair<int, int> > dq;

void check(int row_start, int col_start, int n) {

	int col_end, row_end;
	int i;

	for (i = col_start; i < n; i++) {
		if (M[row_start][i] == 0) {
			col_end = i - 1;
			break;
		}
	}
	if (i == n) col_end = n - 1;

	for (i = row_start; i < n; i++) {
		if (M[i][col_end] == 0) {
			row_end = i - 1;
			break;
		}
	}

	if (i == n) row_end = n - 1;

	// set visit
	for (i = row_start; i <= row_end; i++) {
		for (int j = col_start; j <= col_end; j++)
			visit[i][j] = 1;
	}

	matrix_.push_back({ row_end - row_start + 1, col_end - col_start + 1 });
}
vector<pair<int, int>> matrix;
void sortMatrix() {

	int M_Idx = matrix_.size()-1;
	vector<pair<int, int>> matrix = vector<pair<int, int>>( matrix_.size()+1 , { 0,0 } );

	for (int i = 1; i <= M_Idx; i++)
	{
		matrix[0].first = matrix_[i].first;
		matrix[0].second = matrix_[i].second;

		int Idx = 1;
		int Cur_Col = matrix[0].second;

		for (int j = 1; j <= M_Idx - 1; j++)
		{
			bool Flag = false;
			for (int k = 1; k <= M_Idx; k++)
			{
				if (matrix_[k].first == Cur_Col)
				{
					matrix[Idx].first = matrix_[k].first;
					matrix[Idx].second = matrix_[k].second;
					Cur_Col = matrix[Idx].second;
					Idx++;
					Flag = true;
				}
			}
			if (Flag == false) break;
		}
		if (Idx == M_Idx) break;
	}
}

int solve(int len) {
	int x1, x2, y1, y2;

	for (int i = 0; i < len; i++) {

		for (int j = 0; j < len; j++) {
			if (M[i][j] == 0) //비어있는곳
				continue;
			if (visit[i][j] != 1) { //방문한적이없다
				check(i, j, len);
			}
		}
	}
	
	sortMatrix();

	// DP 이용 계산 
	int INF = 87654321;

	int n = matrix.size() - 1;

	vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

	//dp배열에 초기값 기록하기
	for (int i = 1; i < n; i++) {
		dp[i][i + 1] = matrix[i].first * matrix[i].second * matrix[i + 1].second;
	}

	//dp를 이용한 계산
	for (int m = 2; m <= n; m++) {
		for (int i = 1; i <= n - m; i++) {
			int j = i + m;
			for (int k = i; k < j; k++) {
				int result = dp[i][k] + dp[k + 1][j] + (matrix[i].first * matrix[k].second * matrix[j].second);
				if (!dp[i][j] || dp[i][j] > result) dp[i][j] = result;
			}
		}
	}


	return  dp[1][n];
}


int main() {

	int testcase, temp;
	int n;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {

		cin >> n;
		matrix_ = { {0,0}, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> temp;
				M[i][j] = temp;
				visit[i][j] = 0;
			}
		}

		cout << "#" << t + 1 << " " << solve(n) << endl;

	}

	return 0;
}