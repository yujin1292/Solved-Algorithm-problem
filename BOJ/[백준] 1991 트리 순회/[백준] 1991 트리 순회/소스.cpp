#include <iostream>
#include <vector>
#define MAX 27
using namespace std;

int G[MAX][2];
void print(int i , int root){
	
	if( i==0)
		cout << char(root + 'A');
	if (G[root][0] != '.')
		print(i, G[root][0]);
	if (i == 1)
		cout << char(root + 'A');
	if (G[root][1] != '.')
		print(i, G[root][1]);
	if (i == 2)
		cout << char(root + 'A');
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	char p, l, r;
	for (int i = 0; i < N; i++) {
		cin >> p >> l >> r;
		G[p - 'A'][0] = (l == '.') ? '.' : l - 'A';
		G[p - 'A'][1] = (r == '.') ? '.' : r - 'A';
	}

	
	for (int i = 0; i < 3; i++) {
		print(i, 0);
		cout << "\n";
	}
	return 0;
}