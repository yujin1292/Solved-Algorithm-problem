#include <iostream>

using namespace std;


int **map;
int **ok;
int N;
int X;


int find_ho() {
	int num = 0;
	for (int idx = 0; idx < N; idx++) { //���θ��� üũ�ҰԿ�
		//map[idx][i]
		bool check = true;

		for (int i = 0; i < N-1; i++) {

			//��������
			if (map[idx][i] + 1 == map[idx][i + 1]) {

				if ( (i - X + 1)< 0) {
					check = false;
					break;
				}
				for (int x = 1; x < X; x++) {
					//Ȱ�ַθ� ��ġ���� ����, �����ϴٸ�
					if (ok[idx][i-x] && (map[idx][i] == map[idx][i - x]) ) {
						ok[idx][i - x] = 0;
					}
					else { //��ġ�Ұ���
						check = false;
						break;
					}

				}

				if (check == false)
					break;
				
			}

			//��������
			else if (map[idx][i] - 1 == map[idx][i + 1]) {

				if ((i + X) >= N) {
					check = false;
					break;
				}
				for (int x = 1; x <= X; x++) {
					//Ȱ�ַθ� ��ġ���� ����, �����ϴٸ�
					if (ok[idx][i + x] && (map[idx][i+1] == map[idx][i + x])) {
						ok[idx][i + x] = 0;
					}
					else { //��ġ�Ұ���
						check = false;
						break;
					}

				}
				if (check == false)
					break;
			}
			//������
			else if (map[idx][i] == map[idx][i + 1]) {
				continue;
			}
			//����ĭ ���̰� ���� 
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

	for (int idx = 0; idx < N; idx++) { //���θ��� üũ�ҰԿ�
		//map[i][idx]
		bool check = true;

		for (int i = 0; i < N - 1; i++) {

			//��������
			if (map[i][idx] + 1 == map[i + 1][idx]) {

				if ((i - X + 1) < 0) {
					check = false;
					break;
				}
				for (int x = 1; x < X; x++) {
					//Ȱ�ַθ� ��ġ���� ����, �����ϴٸ�
					if (ok[i - x][idx] && (map[i][idx] == map[i - x][idx])) {
						ok[i - x][idx] = 0;
					}
					else { //��ġ�Ұ���
						check = false;
						break;
					}

				}


				if (check == false)
					break;

			}

			//��������
			else if (map[i][idx] - 1 == map[i + 1][idx]) {

				if ((i + X) >= N) {
					check = false;
					break;
				}
				for (int x = 1; x <= X; x++) {
					//Ȱ�ַθ� ��ġ���� ����, �����ϴٸ�
					if (ok[i + x][idx] && (map[i + 1][idx] == map[i + x][idx])) {
						ok[i + x][idx] = 0;
					}
					else { //��ġ�Ұ���
						check = false;
						break;
					}

				}
				if (check == false)
					break;
			}
			//������
			else if (map[i][idx] == map[i + 1][idx]) {
				continue;
			}
			//����ĭ ���̰� ���� 
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

		//map �����Ҵ�
		map = (int**)malloc(sizeof(int)*N*N);
		ok  = (int**)malloc(sizeof(int)*N*N);
		for (int i = 0; i < N; i++) {
			map[i] = (int*)malloc(sizeof(int)*N);
			ok[i] = (int*)malloc(sizeof(int)*N);
		}
		//���� �Ҵ�
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