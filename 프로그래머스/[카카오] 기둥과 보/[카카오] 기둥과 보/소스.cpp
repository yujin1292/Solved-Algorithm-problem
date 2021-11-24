#include <string>
#include <vector>
#include <iostream>

#define MAX 101
using namespace std;
int N;

vector<vector<int> > answer;
int ceiling[MAX][MAX];
int paillar[MAX][MAX];
bool check_ceiling(int x, int y, int op);
bool check_paillar(int x, int y, int op);

void build_paillar(int x, int y, int op) {
	if (op) paillar[x][y] = 1;
	
	else paillar[x][y] = 0;

	//cout << "build ���" <<x <<","<< y << " " <<  paillar[x][y] << endl;
}
void build_ceiling(int x, int y, int op) {
	if (op) ceiling[x][y] = 1;
	
	else ceiling[x][y] = 0;

	//cout << "build õ��" << x << "," << y << " " << ceiling[x][y] << endl;
}

bool check_ceiling(int x, int y, int op) {
	if (op) { // õ�� ��ġ 
		
		//�ٴڿ� ����ִ��� Ȯ��
		if (paillar[x][y-1]) return true;
		if (x!=N && paillar[x+1][y - 1]) return true;
		// �翷��õ���� �ִ��� Ȯ��
		if (x != 0 && x != N && ceiling[x-1][y] && ceiling[x+1][y])
			return true;

		return false;
	}
	else { //����

		ceiling[x][y] = 0;
		//�������� ����� �� ���� �������� Ȯ�� 
		if (y != N && paillar[x][y] && !check_paillar(x, y , 1)) {
			ceiling[x][y] = 1;
			return false;
		}
		//���������� ����� �� ���� �������� Ȯ�� 
		if (y != N && paillar[x+1][y] && !check_paillar(x+1, y, 1)) {
			ceiling[x][y] = 1;
			return false;
		}

		//���� õ�� ������ ���ʰ������� Ȯ��
		if (x!=0 && ceiling[x-1][y] && !check_ceiling(x-1, y, 1)) {
			ceiling[x][y] = 1;
			return false;
		}
		//���� õ�� ������ ���ʰ������� Ȯ��
		if (x+1!=N && ceiling[x+1][y] && !check_ceiling(x+1, y, 1)) {
			ceiling[x][y] = 1;
			return false;
		}
		ceiling[x][y] = 1;
		return true;
	}
}
bool check_paillar(int x, int y, int op) {
	
	if (op) { // ��ġ
		if (y == 0) return true; //�ǹٴ�
		if (paillar[x][y-1]) return true; //�ؿ� ���������
		if (x!=N && ceiling[x][y]) return true;
		if (x!=0 && ceiling[x - 1][y]) return true; //�ؿ� õ������

		return false;
	}
	else { //���� 
		
		paillar[x][y] = 0;

		//���� ����� �� ���� �������� Ȯ�� 
		if (y != N && paillar[x][y + 1] && !check_paillar(x, y + 1, 1)){
			paillar[x][y] = 1;
			return false;
		}
		//���� õ�� ������ ���ʰ������� Ȯ��
		if (x!=0 && y!=N && ceiling[x-1][y+1] && !check_ceiling(x - 1, y+1, 1) ) {
			paillar[x][y] = 1;
			return false;
		}
		//���� õ�� ������ ���ʰ������� Ȯ��
		if (x!=N && y != N && ceiling[x][y + 1] && !check_ceiling(x, y+1, 1)) {
			paillar[x][y] = 1;
			return false;
		}
		paillar[x][y] = 1;

		return true;
	}
	
}

void build(int i, int j, int frame, int op ) {
	if (frame == 0 )
		build_paillar(i, j, op);
	else
		build_ceiling(i, j, op);
}
bool check(int i, int j, int frame, int op ) {
	if (frame == 0)
		return check_paillar(i, j, op);
	else
		return check_ceiling(i, j, op);
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	N = n;

	for (int i = 0; i < build_frame.size(); i++) {
		if (check(build_frame[i][0], build_frame[i][1], build_frame[i][2], build_frame[i][3])) {	
			build(build_frame[i][0], build_frame[i][1], build_frame[i][2], build_frame[i][3]);
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (paillar[i][j])
				answer.push_back({ i, j,0 });
			if (ceiling[i][j])
				answer.push_back({ i,j,1 });
		}
	}

	return answer;
}

int main() {

	int n = 5;
	vector<vector<int>> v = { {1, 0, 0, 1},{1, 1, 1, 1},{2, 1, 0, 1},{2, 2, 1, 1},{5, 0, 0, 1},{5, 1, 0, 1},{4, 2, 1, 1},{3, 2, 1, 1} , {2,1,0,0} };
	vector<vector<int>> answer = solution(n, v);
	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}

}