#include <iostream>

using namespace std;

long cal(int N, int M, int num) {
	int result = 1;

	if (num == M)
		return 1;
	else
		return N * cal(N, M, num + 1);

}

int main() {
	int testcase = 1;
	int t;
	cin >> t;

	while (testcase ==  t){
		int N, M;
		cin >> N >> M;
		cout << "#" << t + 1 << " " << cal(N,M,0)<<"\n";
		testcase++;
		cin >> t;
	}

	return 0;
}