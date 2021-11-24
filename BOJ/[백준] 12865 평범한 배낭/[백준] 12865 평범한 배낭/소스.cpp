#include <iostream>
#define MAX_BAG 100001
#define MAX_STUFF 101
using namespace std;

int W[MAX_STUFF];
int V[MAX_STUFF];
int bag[MAX_STUFF][MAX_BAG];

int m_max(int a, int b) {
	if (a < b)
		return b;
	else
		return a;
}

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) 
		cin >> W[i] >> V[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (W[i]> j)
				bag[i][j] = bag[i - 1][j];
			else
				bag[i][j] = m_max(bag[i - 1][j], bag[i - 1][j - W[i]] + V[i]);
			
		}
	}
	
	cout << bag[N][K];
	return 0;
}