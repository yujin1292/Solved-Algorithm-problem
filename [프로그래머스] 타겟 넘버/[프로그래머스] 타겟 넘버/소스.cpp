#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int idx, int result) {
	if (idx == numbers.size() - 1) {
		if (result == target) {
			answer++;
		}
		return;
	}
	dfs(numbers, target, idx + 1, result + numbers[idx + 1]);
	dfs(numbers, target, idx + 1, result - numbers[idx + 1]);

}

int solution(vector<int> numbers, int target) {

	dfs(numbers, target, -1, 0);


	return answer;
}
int main() {
	solution({ 1,1,1,1 }, 3);
	return 0;
}