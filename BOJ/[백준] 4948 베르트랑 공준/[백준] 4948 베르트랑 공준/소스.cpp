#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int prime[999999];
vector<int> input;
vector<int> input2;

void findPrime(int n) {
	prime[0] = 1; // 1 은 소수가 아니다.

	int num = sqrt(n);

	for (int i = 2; i <= num; i++) {
		if (prime[i - 1])
			continue;

		for (int j = 2; j*i <= n; j++) {
			prime[i*j - 1] = 1;
		}
	}
}

int main() {
	int N, temp;
	
	while(true)  {
		cin >> temp;
		
		if (temp == 0)
			break;
		else {
			input.push_back(temp);
			input2.push_back(temp);
		}
	}

	sort(input.begin(), input.end());

	temp = input.back();
	findPrime(temp * 2);  //가장 큰수까지 프라임구하기

	int size = input2.size();

	for (int s = 0; s < size ; s++) {
		int count = 0;
		int n = input2[s];

		for (int i = n+1; i <= n*2 ; i++)
			if (prime[i - 1] == 0)
				count++;

		cout << count << "\n";


	}




}