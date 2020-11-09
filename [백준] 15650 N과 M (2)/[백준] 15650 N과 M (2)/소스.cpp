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
	cout << "\n";
}

void dfs(int num, int count) {
	if (num > N)
		return;
	
	if (count == M) {
		print();
		return;
	}

	v.push_back(num+1);
	dfs(num+1, count + 1); //num+1À» ¼±ÅÃ
	v.pop_back();

	dfs(num + 1, count);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	dfs(0, 0);
}