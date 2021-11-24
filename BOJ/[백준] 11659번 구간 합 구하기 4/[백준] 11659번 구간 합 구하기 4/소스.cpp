#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<int> sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int temp, s;
	s = 0;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		s += temp;
		sum.push_back(s);
	}
	int a, b;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		if( a-2 < 0)
			cout << sum[b - 1] << "\n";
		else
			cout << sum[b - 1] - sum[a - 2] << "\n";
	}

	return 0;

}