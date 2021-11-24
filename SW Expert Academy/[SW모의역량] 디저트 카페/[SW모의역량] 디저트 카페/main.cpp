#include <iostream>
#include <vector>

using namespace std;

int map[20][20];
int visit[20][20];
int N;
vector<int> what_i_eat;
int dr[] = { 1, -1, -1, 1 };
int dc[] = { 1, 1, -1 ,-1 };

int max_dessert = -1;
void init() { //visit 초기화

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;
	}
}
void print() {
	cout << "eat\n";
	int size = what_i_eat.size();
	for (int i = 0; i < size; i++) {
		cout<<what_i_eat[i]<<" , ";
	}
	cout << endl;
}

bool in_range(int x, int y) {
	if (0 <= x && x < N) {
		if (0 <= y && y < N) {
			if (visit[x][y] == 0) {
				return true;
			}
		}
	}
	return false;
}

bool eatten(int dessert) {
	int size = what_i_eat.size();
	for (int i = 0; i < size; i++) {
		if (what_i_eat[i] == dessert)
			return false;
	}
	return true;

}

bool can_go(int x, int y, int start_x, int start_y) {
	if ((x == start_x) && (y == start_y)) {
		return true;
	}

	return  in_range(x, y) && eatten(map[x][y]);
}

int eat(int start_c, int start_r, int now_c, int now_r, int count, int di) {
//	cout << now_c << "," << now_r << "\n";
   // 제자리에 돌아왔고, 처음시작이 아니라면 끝내주세요.
	if (start_c == now_c && start_r == now_r && count != 0 && (di == 3)) {
		
		if (count > max_dessert) {
			//cout << "comeback" << count << "----\n";
			max_dessert = count;
			//cout << max_dessert;
			//print();
		}
		return count;
	}
	//대각 방향으로 움직임 

	int next_c = now_c + dc[di];
	int next_r = now_r + dr[di];

	// 갈수 없느 곳임 ( 갔었거나 먹었거나)
	if (can_go(next_c, next_r, start_c, start_r)) {
		what_i_eat.push_back(map[next_c][next_r]);
		visit[next_c][next_r] = 1;

		eat(start_c, start_r, next_c, next_r, count + 1, di);

		visit[next_c][next_r] = 0;
		what_i_eat.pop_back();
	}
	if (di < 3) {

		int n_di = (di + 1) % 4;
		next_c = now_c + dc[n_di];
		next_r = now_r + dr[n_di];

		// 갈수 없느 곳임 ( 갔었거나 먹었거나)
		if (can_go(next_c, next_r, start_c, start_r)) {
			what_i_eat.push_back(map[next_c][next_r]);
			visit[next_c][next_r] = 1;

			eat(start_c, start_r, next_c, next_r, count + 1, n_di);

			visit[next_c][next_r] = 0;
			what_i_eat.pop_back();
		}

	}
	// 다끝났는데 다시돌아오지못했음 
}

int solve() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {

			what_i_eat.push_back(map[i][j]);
			//cout <<"-----\nstrat : "<< i << "," << j << "\n";
			eat(i, j, i, j, 0, 0);
			
			what_i_eat.pop_back();
			init();
		}
	}
	return max_dessert;
}

int main() {
	int testcase;
	cin >> testcase;

	for (int t = 1; t <= testcase; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int temp;
				cin >> temp;
				map[i][j] = temp;
			}
		}
		cout << "#" << t << " " << solve() << "\n";
		max_dessert = -1;
	}
}