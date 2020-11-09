#include <iostream>
#include <vector>
#define MAX 9
using namespace std;

int N, M;
int visit[MAX];

vector<int> v;

void print() {
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void dfs(int num, int count) {
	visit[num] = 1;
	if (num != 0)
		v.push_back(num);
	if (num > N)
		return;
	if (count == M) {
		print();
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i])
			continue;

		dfs(i, count + 1); //num+1À» ¼±ÅÃ
		visit[i] = 0;
		v.pop_back();

	}
	
	
}

int main() {
	cin >> N >> M;
	dfs(0, 0);
}