#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
int visit[10001];

class number {
public :
	int num;
	string instruction;

	number(int a) {
		num = a;
		instruction = "";
	}
	number(int a, string i, int inst) {
		num = a;
		instruction = i;
		if (inst == 0)
			instruction += "D";
		else if (inst == 1)
			instruction += "S";
		else if (inst == 2)
			instruction += "L";
		else
			instruction += "R";
	}
	bool isRight(int n);
};

bool number::isRight(int n) {
	if (num == n) {
		cout << instruction << "\n";
		return true;
	}
	else
		return false;
}

int inst(int instruction, int n) {
	if (instruction == 0)
		return (n*2) % 10000;

	else if (instruction == 1) {
		if (n == 0)
			return 9999;
		return n - 1;
	}
	
	else if (instruction == 2) 
		return (n % 1000) * 10 + n / 1000;
	
	else 
		return (n % 10) * 1000 + n / 10;
	

}
void solve(int l , int r) {
	fill(visit, visit + 10001, 0);
	queue<number> q;

	number left = number(l);
	q.push(left);
	visit[l] = 1;

	while (!q.empty()) {
		number front = q.front();
		q.pop();
		if (front.isRight(r))
			return;

		for (int i = 0; i < 4; i++) {
			int next = inst(i, front.num);
			if (visit[next]) continue;

			visit[next] = 1;
			q.push(number(next, front.instruction, i));
		}
	}

}

int main() {
	int T , l , r;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> l >> r;
		solve(l, r);
	}
	return 0;
}