#include <iostream>
#include <algorithm>

using namespace std;

int const MAX = 16;
int N;
int map[MAX][MAX];

int way = 0;

bool check(pair < int, int> p, int di) {
	if (0 <= p.first&& p.first < N) {
		if (0 <= p.second && p.second < N) {

			if (map[p.first][p.second] == 0) {
				if (di == 3) {
					if (map[p.first - 1][p.second] == 0 && map[p.first][p.second - 1] == 0)
						return true;
					else
						return false;
				}
				else
					return true;
			}		
		}
	}

	return false;
}


void print() {
	cout << "--------\nmap\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 2)
				cout << "X ";
			else if (map[i][j] == 0)
				cout << ". ";
			else
				cout << "O ";
		}
		cout << "\n";
	}
	cout << "--------\n";
}

void move(int di, pair<int,int> p1 , pair<int,int> p2) {
	//print();
	if (p1 != make_pair(0, 0) && p2 != make_pair(0, 1)) { //시작점이아니고
		if (map[N-1][N-1] == 1) {
			//cout << "end!"<<way << endl;
			//print();
			way++;
			return;
		}
	}
	
	pair<int, int> next1;
	pair<int, int> next2;
	switch (di)
	{
	case 1: // 가로방향이면
		
		//가로 
		next1 = make_pair(p1.first, p1.second+1);
		next2 = make_pair(p2.first, p2.second + 1);

		if (check(next2 , 1)) {
			map[p1.first][p1.second] = map[p2.first][p2.second] =0;
			map[next1.first][next1.second] = map[next2.first][next2.second] = 1;
			
			move(1, next1, next2);

			map[next1.first][next1.second] = map[next2.first][next2.second] = 0;
			map[p1.first][p1.second] = map[p2.first][p2.second] = 1;
		}		
		//대각

		next1 = make_pair(p1.first, p1.second + 1);
		next2 = make_pair(p2.first+1, p2.second + 1);

		if (check(next2, 3)) {
			map[p1.first][p1.second] = map[p2.first][p2.second] = 0;
			map[next1.first][next1.second] = map[next2.first][next2.second] = 1;

			move(3, next1, next2);

			map[next1.first][next1.second] = map[next2.first][next2.second] = 0;
			map[p1.first][p1.second] = map[p2.first][p2.second] = 1;
		}

		break;
	case 2: // 세로
		//세로
		next1 = make_pair(p1.first+1, p1.second);
		next2 = make_pair(p2.first+1, p2.second);

		if (check(next2,2)) {
			map[p1.first][p1.second] = map[p2.first][p2.second] = 0;
			map[next1.first][next1.second] = map[next2.first][next2.second] = 1;

			move(2, next1, next2);

			map[next1.first][next1.second] = map[next2.first][next2.second] = 0;
			map[p1.first][p1.second] = map[p2.first][p2.second] = 1;
		}
		//대각
		next1 = make_pair(p1.first+1, p1.second);
		next2 = make_pair(p2.first+1, p2.second + 1);

		if (check(next2,3)) {
			map[p1.first][p1.second] = map[p2.first][p2.second] = 0;
			map[next1.first][next1.second] = map[next2.first][next2.second] = 1;

			move(3, next1, next2);

			map[next1.first][next1.second] = map[next2.first][next2.second] = 0;
			map[p1.first][p1.second] = map[p2.first][p2.second] = 1;
		}
		break;
	case 3: // 대각
		//가로
		next1 = make_pair(p1.first+1, p1.second + 1);
		next2 = make_pair(p2.first, p2.second + 1);

		if (check(next2,1)) {
			map[p1.first][p1.second] = map[p2.first][p2.second] = 0;
			map[next1.first][next1.second] = map[next2.first][next2.second] = 1;

			move(1, next1, next2);

			map[next1.first][next1.second] = map[next2.first][next2.second] = 0;
			map[p1.first][p1.second] = map[p2.first][p2.second] = 1;
		}
		//세로

		next1 = make_pair(p1.first+1, p1.second + 1);
		next2 = make_pair(p2.first+1, p2.second);

		if (check(next2,2)) {
			map[p1.first][p1.second] = map[p2.first][p2.second] = 0;
			map[next1.first][next1.second] = map[next2.first][next2.second] = 1;

			move(2, next1, next2);

			map[next1.first][next1.second] = map[next2.first][next2.second] = 0;
			map[p1.first][p1.second] = map[p2.first][p2.second] = 1;
		}
		//대각

		next1 = make_pair(p1.first+1, p1.second + 1);
		next2 = make_pair(p2.first+1, p2.second + 1);

		if (check(next2,3)) {
			map[p1.first][p1.second] = map[p2.first][p2.second] = 0;
			map[next1.first][next1.second] = map[next2.first][next2.second] = 1;

			move(3, next1, next2);

			map[next1.first][next1.second] = map[next2.first][next2.second] = 0;
			map[p1.first][p1.second] = map[p2.first][p2.second] = 1;
		}
		break;
	}

}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
			if (temp == 1)
				map[i][j] = 2;
		}
	}

	map[0][0] = 1;
	map[0][1] = 1;
	move(1, make_pair(0, 0), make_pair(0, 1));

	cout << way << endl;

	return 0;
}