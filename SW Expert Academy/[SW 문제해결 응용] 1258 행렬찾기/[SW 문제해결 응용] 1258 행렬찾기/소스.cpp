#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const MAX = 100;
int M[MAX][MAX];
int visit[MAX][MAX];

vector< pair<int, int> > mat;


bool cmp(pair<int, int> a, pair<int, int> b) {
	
	if (a.first *a.second == b.first*b.second) {

		return a.first < b.first;
	}

	return a.first*a.second < b.first*b.second;	
}
void check(int a, int b, int n) {

	int x, y;
	int i;

	for ( i = b; i < n; i++) {

		if (M[a][i] == 0) {
			x = i - 1;
			break;
		}
	}
	if (i == n)
		x = n - 1;

	for ( i = a; i < n; i++) {

		if (M[i][x] == 0) {
			y = i - 1;
			break;
		}
	}

	if (i == n)
		y = n - 1;

	for ( i = a; i <= y; i++) {
		for (int j = b; j <= x; j++)
			visit[i][j] = 1;
	}
	//cout << "--> " << y << ", " << x << "\n" <<endl;
	mat.push_back({ y - a +1, x - b+1 });

}
void solve(int n) {
	int x1, x2, y1, y2;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			if (M[i][j] == 0) //비어있는곳
				continue;
			if (visit[i][j] != 1) { //방문한적이없다
				//cout << "point : " << i << "," << j <<  endl;
				check(i, j, n);
			}
		}
	}



	// 답 출력
	sort(mat.begin(), mat.end(), cmp);
	cout << " " << mat.size();
	for (int i = 0; i < mat.size(); i++) 
		cout << " " <<  mat[i].first << " " << mat[i].second;
	cout << "\n";
}



int main() {

	int testcase, temp;
	int n;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {

		cin >> n;
		mat.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> temp;
				M[i][j] = temp;
				visit[i][j] = 0;
			}
		}
		
		cout << "#" << t + 1;
		solve(n);
		
	}

	return 0;
}