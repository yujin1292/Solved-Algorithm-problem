#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int student[31];
	fill(student, student + 31, 1);
	for (int i = 0; i < lost.size(); i++) 
		student[lost[i]]--;
	
	for (int i = 0; i < reserve.size(); i++)
		student[reserve[i]]++;

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (student[i] == 0) {
			if (i + 1 <= n && student[i + 1] == 2) {
				student[i] = student[i + 1] = 1;
				answer++;
				continue;
			}
			if (0<= i - 1 && student[i - 1] == 2) {
				student[i] = student[i - 1] = 1;
				answer++;
			}
		}
		else
			answer++;
	}
	
	return answer;
}