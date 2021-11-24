#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sudoku[10][10];
vector<pair<int, int> > zero;

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << sudoku[i][j]<< " " ;
		cout << "\n";
	}
}

bool solve(int index) {
	if (index == zero.size()) {
		print();
		return true;
	}


	int x, y;
	int number1[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int number2[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int number3[10] = { 0,0,0,0,0,0,0,0,0,0 };

	x = zero[index].first;
	y = zero[index].second;

	// row 숫자 구성 체크
	for (int i = 0; i < 9; i++)
		number1[sudoku[x][i]] = 1;
	// column 숫자 구성 체크
	for (int i = 0; i < 9; i++)
		number2[sudoku[i][y]] = 1;

	// box 숫자 구성 체크
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			number3[sudoku[x / 3 * 3 + i][y / 3 * 3 + j]] = 1;



	for (int i = 1; i < 10; i++) {
		if (number1[i] || number2[i] || number3[i])
			continue;

		number1[i] = number2[i] = 1;
		sudoku[x][y] = i;
		if (solve(index + 1))
			return true;
		number1[i] = number2[i] = 0;
		sudoku[x][y] = 0;

	}

	return false;
}

int main() {

	//입력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0)
				zero.push_back(make_pair(i,j));
		}
	}
	
	cout << "-----------------------------\n";

	solve(0);

	return 0;
}