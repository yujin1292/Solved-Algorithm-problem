#include <string>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

vector<char> priority;
char op[4] = { ' ', '+' , '-' , '*' };
int visit[4] = { 0, 0,0,0 };
long long maxx;
string ex;

long long cal() { //우선순위에 맞게 연산

	int size = ex.size();
	int number = 0;
	vector<long long> results;
	vector<char> operations;

	for (int i = 0; i < size; i++) { // 파싱
		if (ex[i] == '+') {
			results.push_back(number);
			number = 0;
			operations.push_back(ex[i]);
		}
		else if (ex[i] == '-') {

			results.push_back(number);
			number = 0;
			operations.push_back(ex[i]);
		}
		else if (ex[i] == '*') {

			results.push_back(number);
			number = 0;
			operations.push_back(ex[i]);
		}
		else {
			number *= 10;
			number += (ex[i] - '0');
		}
	}
	results.push_back(number);



	for (int j = 0; j < 3; j++) {
		char priorityOp = priority[j];
		int len = operations.size() + results.size();
		vector<long long> results2;
		vector<char> operations2;

		for (int i = 0; i < len; i++) {
			if (i % 2 == 0) { //숫자
				results2.push_back(results[i / 2]);
			}
			else {
				if (operations[i / 2] == priorityOp) { //계산해서 넣기
					long long temp = results2.back();
					results2.pop_back();
					if (priorityOp == '+')
						results2.push_back(temp + results[i / 2 + 1]);
					else if (priorityOp == '-')
						results2.push_back(temp - results[i / 2 + 1]);
					else
						results2.push_back(temp * results[i / 2 + 1]);
					i++;
				}
				else {
					operations2.push_back(operations[i / 2]);
				}
			}
		}
		results = results2;
		operations = operations2;
	}
	return results[0];
}

void dfs(int v, int count) { //우선순위 설정
	if (v != 0) {
		visit[v] = 1;
		priority.push_back(op[v]);
	}

	if (count == 3) { // 계산
		long long temp = cal();
		temp = abs(temp);
		if (maxx < temp)
			maxx = temp;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (visit[i] == 1)
			continue;

		dfs(i, count + 1); // i선택

		visit[i] = 0; //원상복구
		priority.pop_back();

	}
}

long long solution(string expression) {
	maxx = 0;
	ex = expression;
	dfs(0, 0);
	return maxx;
}

