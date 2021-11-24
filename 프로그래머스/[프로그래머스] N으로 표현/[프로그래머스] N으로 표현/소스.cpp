#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

#define MAX  32002

using namespace std;

vector<int> numbers[10];
int counts[MAX];

void match(int a, int b) {
	for (int i = 0; i < numbers[a].size(); i++) {
		for (int j = 0; j < numbers[b].size(); j++) {
			int result;
			//더하기
			result = numbers[a][i] + numbers[b][j];
			if (0 <= result && result < MAX && counts[result] == 0) {
				counts[result] = a + b;
				numbers[a + b].push_back(result);
				
			}
			//빼기
			result = numbers[a][i] - numbers[b][j];
			if (0 <= result && result < MAX && counts[result] == 0) {
				counts[result] = a + b;
				numbers[a + b].push_back(result);
				
			}

			//곱하기
			result = numbers[a][i] * numbers[b][j];
			if ( 0 <= result && result < MAX && counts[result] == 0 ) {
				counts[result] = a + b;
				numbers[a + b].push_back(result);
		
			}

			//나누기
			if (numbers[b][j] == 0)
				continue;

			result = numbers[a][i] / numbers[b][j];

			if (0 <= result && result < MAX && counts[result] == 0) {
				counts[result] = a + b;
				numbers[a + b].push_back(result);
	
			}
		}

	}
}

int solution(int N, int number) {
	int temp = 0;
	for (int i = 1; i <= 8; i++) {
		temp *= 10;
		temp += N;
		if (temp >= MAX)
			break;
		counts[temp] = i;
		numbers[i].push_back(temp);
	}
	for (int i = 2; i <= 8; i++) {
		for (int j = 1; j <= i; j++) {
			match(j, i-j);
		}
	}

	return (int) counts[number] != 0 ? counts[number] : -1;
}

int main() {

	cout << solution(5, 12) ;
	return 0;
}