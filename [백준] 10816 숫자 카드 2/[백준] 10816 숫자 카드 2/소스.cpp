#include <iostream>

#define MAX 10000001
using namespace std;

int positive[MAX];
int negative[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M, num;
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num < 0) 
			negative[num*-1] ++;
		else 
			positive[num] ++;
	}

	cin >> M;
	for (int i = 0; i < M-1; i++) {
		cin >> num;
		if (num < 0)
			cout << (negative[num*-1]) << " ";
		else
			cout<< positive[num] << " ";
		
	}
	cin >> num;
	if (num < 0)
		cout << (negative[num*-1]);
	else
		cout << positive[num];


	return 0;
}
