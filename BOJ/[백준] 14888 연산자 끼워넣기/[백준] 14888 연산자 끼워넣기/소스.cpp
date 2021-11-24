#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 101

using namespace std;

int N;
int number[MAX];
char ops[4] = { '+','-','*','/' };
vector<char> op;

int calculate() {

	int result = number[0];
	for (int i = 0; i < op.size() ; i++) {
		if (op[i] == '+')
			result += number[i + 1];
		else if (op[i] == '-')
			result -= number[i + 1];
		else if (op[i] == '*')
			result *= number[i + 1];
		else if(op[i] == '/')
			result /= number[i + 1];
	}

	return result;
}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> number[i];

	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		for (int t = 0; t < temp; t++)
			op.push_back(ops[i]);
	}

	int result;
	int max = -1000000000;
	int min = 1000000000;

	sort(op.begin(), op.end());

	do {
		result = calculate();

		if (max < result)
			max = result;
		if (min > result)
			min = result;

	} while (next_permutation(op.begin(), op.end() ));

	cout << max << "\n" << min << "\n";

	return 0;
}