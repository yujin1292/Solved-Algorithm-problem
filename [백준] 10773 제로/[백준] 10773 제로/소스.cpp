#include <iostream>
#include <stack>

using namespace std;


int main() {
	int k;
	cin >> k;
	stack<int> numbers;
	int sum = 0;
	int temp;

	for (int i = 0; i < k; i++) {
		cin >> temp;
		sum += temp;
		if (temp == 0) {
			sum -= numbers.top();
			numbers.pop();
			continue;
		}		
		numbers.push(temp);
	}

	cout << sum;
	 

	return 0;
}