#include <iostream>

using namespace std;
int N, K;

int apart[15][14];

void printApart() {
	for (int i = 14; i >= 0; i--) {
		cout << i << "Ãþ\t";
		for (int j = 0; j < 14; j++) {
			cout << apart[i][j] << "\t";
		}
		cout << "\n";
	}
}

int sum(int floor, int roomNum) {
	int result = 0;

	if (floor == 0)
		return roomNum + 1;
	else {
		for (int i = 0; i <= roomNum; i++) {
			result += apart[floor - 1][i];
		}
		return result;
	}
}

void contract() {

	for (int floor = 0; floor < 15; floor++) {
		for (int roomNum = 0; roomNum < 14; roomNum++) 
			apart[floor][roomNum] = sum(floor, roomNum);
	}
}

int main() {

	int testcase; 
	cin >> testcase;

	contract();

	//printApart();

	for (int i = 0; i < testcase; i++) {
		cin >> K >> N;
		cout << apart[K][N-1] << "\n";
	}
}