#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int testcase;
int result;

int numOfClient;
int* visit;
pair<int, int> company;
pair<int, int> home;
pair<int, int>* client;


void print() {
	cout << home.first << "," << home.second << endl;
	cout << company.first << "," << company.second << endl;
	for (int i = 0; i < numOfClient; i++) {
		cout << client[i].first << "," << client[i].second << "\n";
	}
}
void init() {
	result = 999999999;
	cin >> numOfClient;
	cin >> company.first >> company.second;
	cin >> home.first >> home.second;

	client = (pair<int, int>*)malloc(sizeof(pair<int, int>) * numOfClient);
	visit = (int*)malloc(sizeof(int)*numOfClient);
		
}
int distanceOf(int now, int next) {
	int x1, x2, y1, y2;

	if (now == -1) {
		x1 = company.first;
		y1 = company.second;
		x2 = client[next].first;
		y2 = client[next].second;
	}
	else if (next == -1) {
		x1 = client[now].first;
		y1 = client[now].second;
		x2 = home.first;
		y2 = home.second;
	}
	else {
		x1 = client[now].first;
		y1 = client[now].second;
		x2 = client[next].first;
		y2 = client[next].second;
	}
	int a = (x1>x2) ? x1-x2 : x2-x1 ;
	int b = (y1>y2) ? y1-y2 : y2-y1;
	//cout << "cal : " << a << "," << b << "\n";

	return a + b;
}
void dfs(int v, int count, int sum) {
	//cout << "("<< count<<  ") visit : "<< v << " | "<< sum << " \n";
	
	if (v != -1)
		visit[v] = 1; //방문체크

	if (count == numOfClient) {
		//고객의 집을 모두 들렸음 
		int temp = sum + distanceOf(v, -1); //집가는 거리 더하기
		//cout << "total -> " << temp << "\n";
		if (result > temp) { //최소값 업데이트
			result = temp;
		//	cout << "update" << temp << endl;
		}
		return;
	}
	
	for (int i = 0; i < numOfClient; i++) {

		if (visit[i])
			continue;

		dfs(i, count + 1, sum + distanceOf(v, i));
		visit[i] = 0;
	}


}

void solve() {

	dfs(-1, 0 ,0 );

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		
		init();
		
		int x, y;
		for (int j = 0; j < numOfClient ; j++) {
			cin >> x >> y;
			client[j] = pair<int, int>(x, y);
			visit[j] = 0;
		}
	//	print();
		solve();
		cout << "#" << i + 1 << " "<< result << "\n";
	}

}