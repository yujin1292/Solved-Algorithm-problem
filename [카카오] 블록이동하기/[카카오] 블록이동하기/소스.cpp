#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

typedef pair<int, int> pos;
int N;

vector<vector<int>> map;
set<pair<pos, pos> > v;

pair<pos, pos> check(pair<pos, pos> a) {
	pair<pos, pos> temp;
	if (a.first.first == a.second.first) {//가로
		if (a.first.second > a.second.second) {
			temp.first = a.second;
			temp.second = a.first;
			return temp;
		}
		else
			return a;

	}
	else { //세로

		if (a.first.first > a.second.first) {
			temp.first = a.second;
			temp.second = a.first;
			return temp;
		}
		else
			return a;

	}
}
bool isIn2(pos p) {
	return  p.first == N-1 && p.second == N-1;
}
bool isIn(pair < pos, pos> p) {
	return isIn2(p.first) || isIn2(p.second);
}
bool inRange(pos p) {
	if (0 <= p.first && p.first < N)
		if (0 <= p.second && p.second < N)
			return true;

	return false;
}
pos move(int dir , pos p) {

	int dc[] = { 0,1,0,-1 };
	int dr[] = { -1, 0, 1, 0 }; 

	return { p.first + dr[dir] , p.second + dc[dir] };
}
bool isVisit(pair<pos,pos> p) {
	
	if (v.count(p) == 0)
		return false;
	return true;

}
bool isRoad(pos p) {
	return !map[p.first][p.second];
}


int solution(vector<vector<int>> board) {
	int answer = 0;
	N = board.size();
	map = board;

	pair< pos, pos > cur, next;
	queue< pair<pos, pos> >q;
	q.push({ {0,0} , {0,1} });
	v.insert({ { 0,0 }, { 0,1 } });

	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			cur = q.front();
			q.pop();

			if (isIn(cur)) 
				return answer;
			
			//1. 가로로 놓여있을때 같은 row
			if (cur.first.first == cur.second.first) {
				//기본이동
				for (int i = 0; i < 4; i++) {

					next.first = move(i,cur.first);
					next.second = move(i, cur.second);

					if (!inRange(next.first))
						continue;
					if (!inRange(next.second))
						continue;
					if (isVisit(next))
						continue;
					if (!isRoad(next.first) ||!isRoad(next.second) )
						continue;

					q.push(next);
					v.insert(next);
				}


				// 왼쪽 기준 회전 (first 기준) next.second만 움직임
				for (int i = 0; i < 4; i += 2) {
					next.first = cur.first;

					//i방향으로움직이고
					next.second = move(i, cur.second);
					if (!inRange(next.second))
						continue;
					if (!isRoad(next.second))
						continue;

					//3방향으로 움직이기
					next.second = move(3, next.second);
					if (!inRange(next.second))
						continue;
					if (isVisit(next))
						continue;
					if (!isRoad(next.second))
						continue;

					q.push(check(next));
					v.insert(next);

				}
				// 오른쪽 기준 회전 (second 기준) next.first만 움직임 
				for (int i = 0; i < 4; i += 2) {
					next.second = cur.second;

					//i방향으로움직이고
					next.first = move(i, cur.first);
					if (!inRange(next.first))
						continue;
					if (!isRoad(next.first))
						continue;

					//1방향으로 움직이기
					next.first = move(1, next.first);
					if (!inRange(next.first))
						continue;
					if (isVisit(next))
						continue;
					if (!isRoad(next.first))
						continue;

					q.push(check(next));
					v.insert(next);
				}


			}
			
			//2. 세로로 놓여있을때 같은 col
			else {
				//기본이동
				for (int i = 0; i < 4; i++) {
					next.first = move(i, cur.first);
					next.second = move(i, cur.second);
					if (!inRange(next.first))
						continue;
					if (!inRange(next.second))
						continue;
					//방문체크
					if (isVisit(next))
						continue;
					// 갈수있는 길인지 체크 0ㅇ이어야됨..
					if (!isRoad(next.first) ||!isRoad(next.second))
						continue;
					q.push(next);

					v.insert(next);
				}


				// 위쪽 기준 회전(first기준) 
				for (int i = 1; i < 4; i += 2) {
					next.first = cur.first;
					//i방향으로움직이고
					next.second = move(i, cur.second);
					if (!inRange(next.second))
						continue;
					if (board[next.second.first][next.second.second])
						continue;
					//0방향으로 움직이기
					next.second = move(0, next.second);
					if (!inRange(next.second))
						continue;
					if (isVisit(next))
						continue;
					if (board[next.second.first][next.second.second])
						continue;

					q.push(check(next));
					v.insert(next);
				}

				// 오른쪽 기준 회전 (second 기준) 
				for (int i = 1; i < 4; i += 2) {
					next.second = cur.second;

					//i방향으로움직이고
					next.first = move(i, cur.first);
					if (!inRange(next.first))
						continue;
					if (board[next.first.first][next.first.second])
						continue;

					//2방향으로 움직이기
					next.first = move(2, next.first);

					if (!inRange(next.first))
						continue;
					if (isVisit(next))
						continue;
					if (board[next.first.first][next.first.second])
						continue;

					q.push(check(next));
					v.insert(next);
				}
			}		
		}
		answer++;
	}

	return answer;
}


int main() {

	vector<vector<int>> a = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} };

	cout << solution(a);

}