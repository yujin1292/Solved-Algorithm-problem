#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001

using namespace std;

queue<pair<int,int> > ripe;
int box[MAX][MAX];
int M, N;
int yet = 0;
int day = 0;

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

void print() {
	cout << "--------------------" << endl;
	for (int i = 1; i <= N; i++) {
		//익토1 안익토 0 -1은 없음
		for (int j = 1; j <= M; j++) {
			cout << box[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------" << endl;
}

bool inRange(pair<int,int> pos) {
	int x = pos.first;
	int y = pos.second;

	if (1 <= x && x <= N)
		if (1 <= y && y <= M)
			return true;

	return false;
}
bool canRipe(pair<int, int> pos) {
	int x = pos.first;
	int y = pos.second;

	if (box[x][y] == 0)
		return true;
	return false;	
}
bool go () {
	if(yet == 0)
		return true;

	pair<int, int> next;
	pair<int, int> front;

	while (!ripe.empty()) {
		int size = ripe.size();
		while (size--) {
			front = ripe.front();
			for (int i = 0; i < 4; i++) {
				
				next.first = front.first + dr[i];
				next.second = front.second + dc[i];
							
				if (!inRange(next))
					continue;
				if (canRipe(next)) {
					ripe.push(next);
					box[next.first][next.second] = 1;
					yet--;

				}
			}
			//print();
			ripe.pop();
		}
		day++;
	}
	return false;
}

int main() {
	cin >> M >> N;

	int temp;
	for (int i = 1; i <= N; i++) {
		//익토1 안익토 0 -1은 없음
		for (int j = 1; j <= M; j++) {
			cin >> temp;
			if (temp == 0) {
				yet++;
			}
			else if (temp == 1) {
				ripe.push({ i,j });
			}
			
			box[i][j] = temp;
		}

	}
	
	//cout << "안익토 : " << yet << endl;
	bool nothing = go();
	if (nothing) {
		cout << day << endl;
		return 0;
	}

	if (yet != 0)
		cout << -1 << endl;
	else
		cout << day -1 << endl;
}