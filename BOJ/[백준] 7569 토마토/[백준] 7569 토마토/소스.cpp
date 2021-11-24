#include <iostream>
#include <queue>

#define MAX 101

using namespace std;

int dc[] = { 0,0,  1,-1, 0,0 };
int dr[] = { 1,-1, 0,0,  0,0 };
int dh[] = { 0,0,  0,0,  1,-1 };

int unRiped;
int tomato[MAX][MAX][MAX];
int M, N, H;

class toma {
public :
	int m;
	int n;
	int h;

	toma(int h, int n, int m) {
		this->m = m;
		this->n = n;
		this->h = h;
	}
	toma next(int i) {
		return toma(  h + dh[i], n + dr[i], m+dc[i] );
	}
	bool isOK() { //범위안에있으며 안익은 토마토가있다면?
		if (0 <= h && h < H)
			if (0 <= n && n < N)
				if (0 <= m && m < M)
					if (tomato[h][n][m] == 0)
						return true;
		return false;
	}
};
queue<toma>q;

int main() {
	
	cin >> M >> N >> H;
	int temp;


	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> temp;
				tomato[h][n][m] = temp;
				if (temp == 0) {
					unRiped++;
				}
				if (temp == 1) {
					toma temp(h,n,m);
					q.push(temp);
				}
			}
		}
	}
	
	int day = -1;
	while (!q.empty()) {
		int qsize = q.size();

		while (qsize--) {
			toma front = q.front();
			q.pop();

			for (int i = 0; i < 6; i++) {
				toma next = front.next(i);
				if (next.isOK()) {
					q.push(next);
					tomato[next.h][next.n][next.m] = 1; //익힘
					unRiped--;			
				}			
			}
		}

		day++;
	}

	if (unRiped == 0)
		cout << day << endl;
	else
		cout << -1 << endl;

	return 0;

}