#include <iostream>

using namespace std;


int **map;
int **ok;
int N;
int X;


int find_ho() {
	int num = 0;
	for (int idx = 0; idx < N; idx++) { //가로마다 체크할게여
		//map[idx][i]
		bool check = true;

		for (int i = 0; i < N-1; i++) {

			//높아질때
			if (map[idx][i] + 1 == map[idx][i + 1]) {

				if ( (i - X + 1)< 0) {
					check = false;
					break;
				}
				for (int x = 1; x < X; x++) {
					//활주로를 설치한적 없고, 평평하다면
					if (ok[idx][i-x] && (map[idx][i] == map[idx][i - x]) ) {
						ok[idx][i - x] = 0;
					}
					else { //설치불가능
						check = false;
						break;
					}

				}

				if (check == false)
					break;
				
			}

			//낮아질때
			else if (map[idx][i] - 1 == map[idx][i + 1]) {

				if ((i + X) >= N) {
					check = false;
					break;
				}
				for (int x = 1; x <= X; x++) {
					//활주로를 설치한적 없고, 평평하다면
					if (ok[idx][i + x] && (map[idx][i+1] == map[idx][i + x])) {
						ok[idx][i + x] = 0;
					}
					else { //설치불가능
						check = false;
						break;
					}

				}
				if (check == false)
					break;
			}
			//같을때
			else if (map[idx][i] == map[idx][i + 1]) {
				continue;
			}
			//여러칸 차이가 날때 
			else {
				check = false;
				break;
			}


		}

		if (check) {
			num++;
		//	cout << idx << endl;
		}

	}
	return num;
}
int find_ve() {
	int num = 0;

	for (int idx = 0; idx < N; idx++) { //가로마다 체크할게여
		//map[i][idx]
		bool check = true;

		for (int i = 0; i < N - 1; i++) {

			//높아질때
			if (map[i][idx] + 1 == map[i + 1][idx]) {

				if ((i - X + 1) < 0) {
					check = false;
					break;
				}
				for (int x = 1; x < X; x++) {
					//활주로를 설치한적 없고, 평평하다면
					if (ok[i - x][idx] && (map[i][idx] == map[i - x][idx])) {
						ok[i - x][idx] = 0;
					}
					else { //설치불가능
						check = false;
						break;
					}

				}


				if (check == false)
					break;

			}

			//낮아질때
			else if (map[i][idx] - 1 == map[i + 1][idx]) {

				if ((i + X) >= N) {
					check = false;
					break;
				}
				for (int x = 1; x <= X; x++) {
					//활주로를 설치한적 없고, 평평하다면
					if (ok[i + x][idx] && (map[i + 1][idx] == map[i + x][idx])) {
						ok[i + x][idx] = 0;
					}
					else { //설치불가능
						check = false;
						break;
					}

				}
				if (check == false)
					break;
			}
			//같을때
			else if (map[i][idx] == map[i + 1][idx]) {
				continue;
			}
			//여러칸 차이가 날때 
			else {
				check = false;
				break;
			}


		}
		if (check) {
			num++;
		//	cout << idx << endl;
		}

	}
	return num;
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ok[i][j] = 1;
		}
	}
}
int solve() {

	int hor = 0;
	int ver = 0;
	
	hor = find_ho();
	init();
	ver = find_ve();

	return  hor + ver;
}

int main() {
	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {

		cin >> N >> X;

		//map 동적할당
		map = (int**)malloc(sizeof(int)*N*N);
		ok  = (int**)malloc(sizeof(int)*N*N);
		for (int i = 0; i < N; i++) {
			map[i] = (int*)malloc(sizeof(int)*N);
			ok[i] = (int*)malloc(sizeof(int)*N);
		}
		//지도 할당
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int temp;
				cin >> temp;
				map[i][j] = temp;
				ok[i][j] = 1;
			}
		}

		cout << "#" << t + 1 << " " << solve() << "\n";
		
	}


	return 0;
}