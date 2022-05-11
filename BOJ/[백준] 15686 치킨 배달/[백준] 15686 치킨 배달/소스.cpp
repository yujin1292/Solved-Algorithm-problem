#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N, M;
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;


int main() {

	int temp;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 2) chicken.push_back(make_pair(i, j));
			else if (temp == 1) house.push_back(make_pair(i, j));
		}
	}


	int houseSize = house.size();
	int chickenSize = chicken.size();

	vector<int> bitMask(chickenSize);
	for (int i = 0; i < M; i++)
		bitMask[chickenSize - 1 - i] = 1;


	int answer = 999999999;
	do {
		int result = 0;
		for (int h = 0; h < houseSize; h++) {
			int distance = 9999999; // 집의 치킨거리구함
			for (int i = 0; i < chickenSize; i++) {
				if (bitMask[i] == 1) {
					// 폐업 안함 
					int temp = abs(chicken[i].first - house[h].first) + abs(chicken[i].second - house[h].second);
					if (distance > temp) distance = temp;
				}
			}

			result += distance;
		}
		if (answer > result) answer = result;

	} while (next_permutation(bitMask.begin(), bitMask.end()));


	cout << answer << "\n";
	return 0;
}