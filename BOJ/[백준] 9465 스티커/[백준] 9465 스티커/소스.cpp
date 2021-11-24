#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int t, n, a[2][100000];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++) 
				cin>>  a[i][j];

		a[0][1] = max(a[0][0], a[0][1] + a[1][0]); // 두번째 열에 대해서는
		a[1][1] = max(a[1][0], a[0][0] + a[1][1]); // 직접 구해둠. 첫번째 열은 기존 입력값

		for (int i = 2; i < n; i++) {
			a[0][i] = max( max(a[1][i - 1], a[1][i - 2]) , a[0][i-2] )  + a[0][i];
			a[1][i] = max( max(a[0][i - 1], a[0][i - 2]) , a[1][i-2] )+ a[1][i];
		}
		cout<< max(a[0][n - 1], a[1][n - 1]) << "\n";

	}
}