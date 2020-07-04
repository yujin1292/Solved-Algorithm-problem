#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int N;
int p, m, mul, d;
vector<int> num;
vector<int> results;

int cal(vector<char>op) {
	int result = num[0];
//	cout << num[0];

	for (int i = 0; i <N-1; i++) {
	//	cout << " "<< op[i] <<" "<< num[i+1];
		if (op[i] == '+') {
			result += num[i+1];
		}
		else if (op[i] == '-') {
			result -= num[i+1];
		}
		else if (op[i] == '*') {
			result *= num[i+1];
		}
		else {
			result /= num[i+1];
		}
	}
//	cout << " = "<< result << "\n";
	return result;
}

void select(vector<char> op ,int p_n, int m_n, int mul_n, int d_n ) {
	if ((N - 1) == (p_n + m_n + mul_n + d_n)) {
		//∞ËªÍ 
		int temp = cal(op);
		results.push_back(temp);

		return;
	}

	//¥ı«œ±‚
	if (p_n < p ) {
		op.push_back('+');
		select(op, p_n + 1, m_n, mul_n, d_n);
		op.pop_back();
	}
	//ª©±‚
	if (m_n < m) {

		op.push_back('-');
		select(op, p_n, m_n+1, mul_n, d_n);
		op.pop_back();
	}
	//∞ˆº¿
	if (mul_n < mul) {

		op.push_back('*');
		select(op, p_n, m_n, mul_n + 1, d_n);
		op.pop_back();
	}
	//≥™¥∞º¿
	if (d_n < d) {

		op.push_back('/');
		select(op, p_n, m_n, mul_n, d_n +1);
		op.pop_back();
	}
}


int solve() {
	vector<char>op;
	select(op, 0, 0, 0, 0);
	
	sort(results.begin(), results.end());

	return results.back() - results[0];
}

int main() {

	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		cin >> N;
		cin >> p >> m>> mul >> d;
		
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			num.push_back(temp);
		}

		cout << "#" << t + 1 << " " << solve()<<"\n";
		num.clear();
		results.clear();

	}
}