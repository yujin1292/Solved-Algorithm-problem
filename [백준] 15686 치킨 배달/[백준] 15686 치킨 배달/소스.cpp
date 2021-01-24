/*
	백준에서 메모리 초과로 실패
	이유 아직 알수없음

*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N, M;
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;
vector<vector<pair<int,int>> > selected; //선택된 치킨 위치 저장

int result = 999999999;

void dfs(int index , vector<pair<int,int>> s) {

	if (s.size() == M) {
		selected.push_back(s);
		return;
	}

	for (int i = index; i < chicken.size(); i++) {
		s.push_back(chicken[i]);
		dfs(i+1, s); //중복되지않도록 다음번엔 i+1 부터 선택
		s.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 1) chicken.push_back(make_pair(i, j));
			else if (temp == 2) house.push_back(make_pair(i, j));
		}
	}

	vector<pair<int, int>> s;
	dfs(0,s);

	for (vector<pair<int, int>> selec : selected) {
		int temp_sum = 0;
		for (pair<int,int> h : house) {
			temp = 999999999;
			for (pair<int, int> chicken_se : selec) {
				int dx = h.first - chicken_se.first;
				int dy = h.second - chicken_se.second;
				if (dx <= 0) dx *= -1;
				if (dy <= 0) dy *= -1;

				if (temp > dx + dy)
					temp = dx + dy;
			}
			temp_sum += temp;
		}
		
		if (result > temp_sum)
			result = temp_sum;
	}

	cout << result << "\n";
	return 0;
}