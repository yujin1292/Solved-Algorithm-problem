#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int const MAX = (12 * 15) + 1;

int N, W, H;
int ** map;

int min_block;

int dx[] = { 1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int** copy() {
	int** cp = (int**)malloc(sizeof(int)* W * H);
	for (int i = 0; i < H; i++) {
		cp[i] = (int*)malloc(sizeof(int) * W);
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
		
			cp[i][j] = map[i][j];
		}
	}

	return cp;
}

int count(int ** cp) {
	int c = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (cp[i][j] != 0)
				c++;
		}
	}

	return c;
}

void print(int **cp) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << cp[i][j] << " ";
		}
		cout << endl;

	}
}

void pushdown(int **cp) {
	//������ 
	for (int w = 0; w < W; w++) {
		for (int h = H - 1; h >= 0; h--) {
			if (cp[h][w] == 0) {//����� ã��
				//���� ã�� 
				int i;
				for ( i= h; i > 0; i--) {
					if (cp[i][w] != 0)
						break;
				}
				//i�� ������ ������
				
				for (int k = 0; k <= i; k++) {
					cp[h - k][w] = cp[i - k][w];
				}

				for (int k = 0; k < (h - i); k++) {
					cp[k][w] = 0;
				}
				
			}
		}
	}

}
//bfs �� ���� block break!
void  break_block(vector<int> pos) {
	
	if (min_block == 0) { //�ּҰ����͹������ϱ� ������ 
		return;
	}

	int ** cp_map = copy();
	queue<pair<int,int> > q;
	int h;
	int num;

	for (int ball = 0; ball < pos.size(); ball++) {
		
		int b_pos = pos[ball] -1 ;

		//�� ������ ��Ȯ�� ��ġ ã�� 
		for (h = 0; h < H; h++) {
			if (cp_map[h][b_pos] != 0) {
				num = cp_map[h][b_pos];
				q.push(make_pair(h, b_pos));
				break;
			}
		}

		while (!q.empty()) {
			
			pair<int,int>  now = q.front();
			q.pop();


			//break
			num = cp_map[now.first][now.second];
			cp_map[now.first][now.second] = 0;
			
			//��������� �ֵ� push 
			for (int di = 0; di < 4; di++) {
				int x = now.first;
				int y = now.second;

				for (int i = 0; i < num - 1 ; i++) {
					x += dx[di];
					y += dy[di];
					if (0<=x && x < H && 0<=y &&  y < W) {
						if (cp_map[x][y] != 0)
							q.push(make_pair(x, y));
					}
					else {
						break;
					}
				}
			}
		}
	
		//����
		pushdown(cp_map);
		
	
	}

	//������ �Ŀ� ����block ����
	int count_block = count(cp_map);

	//min �� ����
	if (min_block > count_block) {
		min_block = count_block;
	}
	
}



//dfs�� ���� ��� ����� �� ����

void  ball(int x, int count ,vector<int> pos) {

	if (min_block == 0) { //�ּҰ����͹������ϱ� ������ 
		return;
	}

	if (count == N ) {
	/*	cout << " ���� : ";
		for (int i = 0; i < pos.size(); i++)
			cout << pos[i] << " ";
		cout << endl;*/
 
		break_block(pos);
		return;

	}

	if (x == W ) { // �������� �����ߴµ� ���� ���Ѱ�� 
		return;
	}

	//����
	pos.push_back(x+1);
	ball(0 , count+ 1 ,pos);//�ٽ� 0���� 
	
	pos.pop_back();
	//���þ���
	ball(x + 1, count,pos);

}

int solve() {
	vector<int> pos;

	
	//dfs�� ���� Ž��
	ball(0, 0,pos);


	return min_block;
}

int main() {

	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {

		min_block = MAX;
		cin >> N >> W >> H;

		//map  �����Ҵ�
		map = (int**) malloc(sizeof(int)* W * H);
		for (int i = 0; i < H; i++) {
			map[i] = (int*)malloc(sizeof(int) * W);
		}

		for (int i = 0; i < H; i++) {
			
			for (int j = 0; j < W; j++) {
				int temp;
				cin >> temp;
				map[i][j] = temp;
			}
		}

		cout << "#" << t+1 << " " << solve()<<"\n";

		
	}
	   
	return 0;

}
