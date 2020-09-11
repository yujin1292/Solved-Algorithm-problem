#include <iostream>

using namespace std;

int han(int cur, int n , int cnt) {
	if (cur > n)
		return cnt;	

	if (cur < 100)  // 한자리, 두자리
		han(cur + 1, n, cnt + 1);	
	else if (cur < 1000) { //세자리
		int a = cur % 1000 / 100;
		int b = cur % 100 / 10;
		int c = cur % 10;
		if (a - b == b - c) 
			han(cur + 1, n, cnt + 1);		
		else 
			han(cur + 1, n, cnt);
	}
	else  // 1000인 경우 어짜피 한수아님
		han(cur + 1, n, cnt);
}


int main() {
	int n;
	cin >> n;
	cout << han(1, n, 0) << endl;
	int count = 0;
	//for (int i = 1; i <= n; i++) {
	//	if (i < 100) count = i;
	//	else if( i<1000) {
	//		int a = i % 1000 / 100;
	//		int b = i % 100 / 10;
	//		int c = i % 10;

	//		if (a - b == b - c) {
	//			count++;
	//		}
	//	}

	//}
	//cout << count << endl;
	return 0;
}