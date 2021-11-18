#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int n, k;


int visit[100100]; // 방문한 시간(방문여부) 저장
int discover[100100]; // discover[i] = j   j->i 로 움직였음
queue<int> q;
vector<int> v;

bool inRange(int nxt) {
	return  (nxt >= 0 && nxt <= 100000);
}

void bfs() {

	visit[n] = 0;
	q.push(n);

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		if (cur == k) {
			cout << visit[k] << endl;
			return;
		}
		
		int next = cur - 1;
		if (inRange(next) && visit[next] == 0) {
			q.push(next);
			discover[next] = cur;
			visit[next] = visit[cur] + 1;
		}
		
		next = cur + 1;
		if (inRange(next) && visit[next] == 0) {
			q.push(next);
			discover[next] = cur;
			visit[next] = visit[cur] + 1;
		}

		next = cur * 2;
		if (inRange(next) && visit[next] == 0) {
			q.push(next);
			discover[next] = cur;
			visit[next] = visit[cur] + 1;
		}

	}
}

int main() {

	cin >> n >> k;
	bfs();

	int index = k;;
	v.push_back(k);
	// 경로 추적해서  v에 저장
	while (index != n) {
		v.push_back(discover[index]);
		index = discover[index];
	}
	//경로 출력
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << ' ';
	}

}