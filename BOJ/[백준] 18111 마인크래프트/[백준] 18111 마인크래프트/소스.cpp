#include <iostream>
#define MAX 501
using namespace std;

int N, M, B;
int ground[MAX][MAX];

int main() {
	cin >> N >> M >> B;
	
	int min = 257;
	int max = -1;

	int min_time = 999999999;
	int max_height = -1;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ground[i][j];
			if (min > ground[i][j]) min = ground[i][j];
			if (max < ground[i][j]) max = ground[i][j];
		}
	}
	

	for (int h = min; h <= max; h++) {

		int B1 = B;
		int time = 0;

		int build, remove;
		build = remove = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int temp = (ground[i][j] - h);

				if (temp > 0) { //땅 제거 , 인벤토리에담기
					remove += temp;
				}
				else if( temp <0 ){ // 땅 쌓기, 인벤토리에서 꺼내기
					build -= temp;
				}
			}


		}
		if (remove + B >= build) {
			time = remove * 2 + build;
			if (min_time >= time) {
				min_time = time;
				max_height = h;
			}
		}
	
	}

	cout << min_time << " " << max_height;

	return 0;
}