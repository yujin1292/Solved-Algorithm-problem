#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int now = 0;
	int idx = 0;
	queue<int> q;

	for (int i = 0; i < bridge_length; i++)
		q.push(0);

	while (!q.empty()) {
		answer++;
		now -= q.front();
		q.pop();

		if (idx < truck_weights.size() && now + truck_weights[idx] <= weight) {
			q.push(truck_weights[idx]);
			now += truck_weights[idx];
			idx++;
		}
		else if(idx != truck_weights.size()) {
			q.push(0);
		}	
	}

	return answer;
}

int main() {
	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = { 7,4,5,6 };

	cout << solution(bridge_length, weight, truck_weights) << endl;
	return 0;
}