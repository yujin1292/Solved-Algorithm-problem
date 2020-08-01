#include <iostream>

using namespace std;

int W, H, N;


void solve() {
	int floor;
	int roomNum;

	floor = N % H;
	roomNum = N / H + 1;
	if (floor == 0) {
		floor = H;
		roomNum = N / H;
	}

	floor *= 100;

	cout << floor + roomNum << "\n";
	
}

int main() {
	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		cin >> H >> W >> N;
		solve();
	}

}