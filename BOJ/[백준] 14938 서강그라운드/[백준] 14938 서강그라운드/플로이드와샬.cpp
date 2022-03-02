/*

#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_V = 101;
const int INF = 15000001;

int n, m, r;

int dist[MAX_V][MAX_V];
int item[MAX_V];

int main(){

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < r; i++){
		int a, b, l;
		cin >> a >> b >> l;
		if( dist[a][b] > l){
			dist[a][b] = l;
			dist[b][a] = l;
		}
	}

	// Floyd warshall
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j];
			
	
	int answer = 0;
	for (int landing = 1; landing <= n; landing++) {
		int gets = 0;
		for (int move_to = 1; move_to <= n; move_to++) {
			if (dist[landing][move_to] <= m)
				gets += item[move_to];
		}
		if (answer < gets) answer = gets;
	}
	
	cout << answer << endl;
	return 0;
}

*/