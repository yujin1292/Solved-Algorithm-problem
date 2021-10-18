#include <string>
#include <vector>

#define max 1001


using namespace std;

int triangle[max][max];

vector<int> solution(int n) {
	vector<int> answer;

	int dc[3] = { 0,1,-1 };
	int dr[3] = { 1,0,-1 };


	int size = n;
	int number = 0;
	int row = 0;
	int col = 1;

	for (int i = 0; i < n; i++) {
		int direction = i % 3;
		for (int j = 0; j < size; j++) {
			row += dr[direction];
			col += dc[direction];
			number++;

			triangle[row][col] = number;

		}
		size--;
	}



	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++) 
			answer.push_back(triangle[i][j]);
		
	

	return answer;
}