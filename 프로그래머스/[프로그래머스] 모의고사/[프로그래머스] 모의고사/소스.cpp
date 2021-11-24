#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	int ans1[] = { 1,2,3,4,5 };
	int ans2[] = { 2,1,2,3,2,4,2,5 };
	int ans3[] = { 3,3,1,1,2,2,4,4,5,5 };
	int supos[] = { 0,0,0 };
	vector<int> answer;

	for (int i = 0; i < answers.size(); i++) {
		if (ans1[i % 5] == answers[i])
			supos[0]++;
		if (ans2[i % 8] == answers[i])
			supos[1]++;
		if (ans3[i % 10] == answers[i])
			supos[2]++;
	}

	int max = -1;
	for (int i = 0; i < 3; i++) {
		if (max < supos[i]) {
			max = supos[i];
			answer.clear();
			answer.push_back(i + 1);
		}
		else if (max == supos[i])
			answer.push_back(i + 1);
	}
	return answer;
}