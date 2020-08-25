#include <iostream>
#include <vector>

using namespace std;

long ans = 0;

long N; //시험장 수
vector<int> classroom;

long B; // 총감독이  한시험장에 감시할수있는 응시자수
long C; // 부감독관이 감시할수있는 수

	   //총감독은 한명, 부감독관은 여러명


void solve() {

	for (long i = 0; i < N; i++) {
		classroom[i] -= B; // 총감독관이 감시하는건 다빼야함
	}
	ans += N;

	for (long i = 0; i < N; i++) {
		if (classroom[i] <= 0)
			continue;
		ans += (classroom[i] / C);
		if (classroom[i] % C != 0)
			ans++;
	}

	cout << ans;
}

int main() {
	cin >> N;

	for (long i = 0; i < N; i++) {
		long temp;
		cin >> temp;
		classroom.push_back(temp);
	}

	cin >> B >> C;
	
	solve();


	return 0;
}