#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long 
#define MAX 1000001
using namespace std;

int v[MAX];

int main() {
	fastio;

	int N;
	ll S;
	cin >> N >> S;
	for (int i = 0; i < N; i++)cin >> v[i];

	int start = -1, end = -1, result = MAX;
	ll sum = 0;

	while ( start <= end  && end < N) {
		if ( S <= sum) { // 답은 가능 , 줄여야됨 
			if (result > (end - start)) result = end - start;
			start++;
			sum -= v[start];
		}
		else if (S > sum) { // 더 더해야한다
			end++;
			sum += v[end];
		}
	}
	if (result == MAX) result = 0;
	cout << result << endl;
	return 0;
}