#include <iostream>
#include <string>
#include <vector>

#define MAX 51

using namespace std;
int N, M;
int chess[MAX][MAX]; 



vector<char> line1 = { 'B','W','B','W' ,'B','W' ,'B','W' };
vector<char> line2 = { 'W','B','W' ,'B','W' ,'B','W','B' };
vector<vector<char> > board1, board2;
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




string ver1[8] = {
   { "WBWBWBWB" },
   { "BWBWBWBW" },
   { "WBWBWBWB" },
   { "BWBWBWBW" },
   { "WBWBWBWB" },
   { "BWBWBWBW" },
   { "WBWBWBWB" },
   { "BWBWBWBW" },
};
string ver2[8] = {
   { "BWBWBWBW" },
   { "WBWBWBWB" },
   { "BWBWBWBW" },
   { "WBWBWBWB" },
   { "BWBWBWBW" },
   { "WBWBWBWB" },
   { "BWBWBWBW" },
   { "WBWBWBWB" },
};
int checkBlock2(int x, int y) {

	int result1, result2;
	result1 = result2 = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//ver.1 비교
			if (ver1[i][j] != chess[x + i][y + j])
				result1++;

			//ver.2 비교
			if (ver2[i][j] != chess[x + i][y + j])
				result2++;

		}
	}

	//최솟값을 반환

	if (result1 < result2)
		return result1;
	else
		return result2;

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
	int result2 = 999999;

	int temp,temp2;
	for (int i = 0; i < N - 7 ; i++) {
		for (int j = 0; j < M - 7; j++) {
			// 잘린 보드에서 개수 셈

			//ver1
			temp = checkBlock2(i, j);
			if (result > temp) //최솟값 업데이트
				result = temp;
			
		
		}
	}

	cout << result;
}