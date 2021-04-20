#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
	vector<vector<int>> tri = triangle;

	for (int i = tri.size() - 1; i > 0; i--) 
		for (int j = 0; j < tri[i].size() - 1; j ++ ) 
			tri[i - 1][j] += max(tri[i][j], tri[i][j + 1]);

	return tri[0][0];
}

int main() {


	vector<vector <int>> tri = { {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };

	cout << solution(tri);
	return 0;
	
}