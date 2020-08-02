#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int isPrime[10001];

bool cmp(pair<int, int> left, pair<int, int> right) {
	return abs(left.second - left.first) < abs(right.second - right.first);
}

void prime() {
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j <= 10000; j++) {
			if (i*j > 10000)
				break;
			isPrime[ i*j - 1] = -1; // ¼Ò¼ö°¡ ¾Æ´Ô
			
		}
	}

	isPrime[0] = -1;
}

void print() {
	for (int i = 0; i < 10000; i++) {
		if( isPrime[i] != -1)
			cout << i + 1 << " ";
	}
}
void solve(int num ) {
	vector< pair<int, int> > results;
	for (int i = 0; i < num/2 + 1 ; i++) {
		if (isPrime[i] == -1)
			continue; // ¼Ò¼ö°¡ ¾Æ´Ô

		if (isPrime[num - i - 2] == -1) {
			continue; //¼Ò¼ö°¡¾Æ´Ô
		}
		else {
			results.push_back({ i + 1, num- (i +1) });
		}

	}

	sort(results.begin(), results.end(), cmp);
	if (results.front().first < results.front().second)
		cout << results.front().first << " " << results.front().second << "\n";
	else
		cout << results.front().second << " " << results.front().first << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, temp;
	prime();
	//print();
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> temp;
		solve(temp);
	}

	return 0;
}