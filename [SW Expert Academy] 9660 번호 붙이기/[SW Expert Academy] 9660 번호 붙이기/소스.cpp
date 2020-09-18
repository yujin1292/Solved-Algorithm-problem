#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int T, N, temp;
vector<int> hate;
int * numbers;

bool isRight() {
	for (int i = 0; i < N; i++)
		cout << numbers[i] << " ";
	cout << endl;
	for (int i = 0; i < N; i++)
		cout << hate[i] << " ";
	cout << endl;
	cout << endl;

	for (int i = 0; i < N; i++) {
		if (numbers[i] == hate[i])
			return false;
	}
	return true;

}


int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		long long count = 0;

		cin >> N;
		numbers = (int*)malloc(sizeof(int)*N);
		for (int i = 0; i < N; i++) {
			numbers[i] = i + 1;
			cin >> temp;
			hate.push_back(temp);
		}
		
		sort(numbers, numbers + N); 
		do {			
			if (isRight()) {
				count++;
				count %= MOD;
			}
		} while (next_permutation(numbers, numbers + N));
		hate.clear();

		cout << "#" << t + 1 << " " << count << "\n";
	}


	return 0;
}