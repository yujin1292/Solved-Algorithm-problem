#include <string>
#include <vector>
#include <stack>

using namespace std;

int gcd(int x, int y) {
	int temp;
	int smaller = x > y ? y : x;
	int bigger = x > y ? x : y;

	while (smaller != 0) {
		int rest = bigger % smaller;
		bigger = smaller;
		smaller = rest;
	}
	return bigger;
}

int lmc(int a, int b) {
	//return (a * b) / gcd(a, b);
	return a / gcd(a, b) * b;
}

int solution(vector<int> arr) {
	int answer = 0;

	stack<int> s;
	for (auto num : arr) s.push(num);
	
	while (true) {
		if (s.size() >= 2) {
			int temp = s.top();
			s.pop();
			int temp2 = s.top();
			s.pop();

			s.push(lmc(temp, temp2));
		}
		else break;
	}

	return s.top();
}

int main() {
	printf("%d", solution({ 2,3,4 }));
	return 0;
}