#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>


#define MAX 30
using namespace std;

int M, N;
vector<string> Board;
vector< pair<int, int> > poplist;

int answer = 0;

void init(int m, int n, vector<string> board) {
	M = m;
	N = n;
	Board = board;
}
bool inRange(pair<int,int> a) { 
	int x = a.first;
	int y = a.second;

	if (0 <= x && x < M)
		if (0 <= y && y < N)
			return true;
	return false;
}
void print() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << Board[i][j] << " ";

		cout << endl;
	}
	cout << "-------------------\n";
}

void check(int x, int y) { // 터트릴부분 체크하기
	pair<int, int> next;
	char icon = Board[x][y];
	if (icon == ' ')
		return;

	int dr[] = { 0,1,1 };
	int dc[] = { 1,0,1 };


	for (int i = 0; i < 3; i++) {
		next = make_pair(x + dr[i], y + dc[i]);
	
		if (!inRange(next))
			return;

		if (Board[next.first][next.second] != icon)
			return;
	}

	poplist.push_back(make_pair(x, y));

}

void pop(pair<int, int> p) { //한칸 터트리기
	int j = p.second;	
	for (int i = p.first -1 ; i >= 0; i --)
		Board[i + 1][j] = Board[i][j];

	Board[0][j] = ' ';

	answer++;

}

void goPop() { //사각형 터트리기

	int dr[] = { 0,1,1 };
	int dc[] = { 1,0,1 };
	pair<int, int> p, next;

	set< pair<int, int>, less<pair<int, int>> > poplist2;
	set< pair<int, int>, less<pair<int,int>>  > ::iterator iter;
	
	
	for (int i = 0; i < poplist.size(); i++) {
		p = poplist[i];
		poplist2.insert(p);
		for (int j= 0; j < 3; j++) {
			next = make_pair(p.first + dr[j], p.second + dc[j]);
			poplist2.insert(next);
		}
	}
		

	for (iter = poplist2.begin(); iter != poplist2.end(); iter++)
		pop(*iter);

	poplist.clear();
	poplist2.clear();

	print();
}




int solution(int m, int n, vector<string> board) {
	init(m,n,board);

	do {

		goPop();
		

		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				check(i, j);
			}
		}
		

	} while (!poplist.empty());



	return answer;
}

int main() {
	vector<string> temp = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
	
	cout << solution(4, 5, temp);
}