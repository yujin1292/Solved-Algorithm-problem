#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int prime[1000];
vector<int> input;

void findPrime(int n) {
	prime[0] = 1; // 1 은 소수가 아니다.

	int num = sqrt(n);

	for (int i = 2; i <= num; i++) {
		if (prime[i - 1])
			continue;

		for (int j = 2; j*i <=  n; j++) {
			prime[i*j - 1] = 1;
		}
	}
}


void print(int n) {
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " : " << prime[i] << " \n";
	}
}

int main() {
	int N, temp;
	cin >> N;
	
	
	for (int i = 0; i < N; i++) {
		cin >> temp;
		input.push_back(temp);
	}

	sort(input.begin(), input.end());
	
	findPrime(input.back()); //가장 큰수까지 프라임구하기
	
	//print(input.back());
	

	int count = 0;
	for (int i = 0; i < N; i++) 
		if (prime[ input[i] -1 ] == 0) 
			count++;
	
	cout << count << "\n";

}