#include <iostream>
#include <algorithm>

using namespace std;

// paycheck[i] : i일까지 상담을 마치고 i일에 정산된 총 금액
int paycheck[16];

int main() {

	int N, t, p;
	cin >> N;

	for (int day = 1; day <= N; day++) {
		cin >> t >> p;

		// 상담을 끝까지 마칠 수 없는 경우는 고려하지 않는다.
		if (day + t - 1 > N) continue;


		// 상담 시작일 전에 벌어둔 최고금액을 가져온다
		int before = 0;
		for (int i = 1; i < day; i++) {
			if (before < paycheck[i]) before = paycheck[i];
		}

		// 해당 상담이 끝나는 날( day + t - 1 )
		paycheck[day + t - 1] = max( before + p , paycheck[day + t - 1]);
		// 해당 상담을 포기한다  -> paycheck[day+t-1] = paycheck[day+t-1]  (상태유지)
		// 해당 상담을 진행한다  -> paycheck[day+t-1] = day 전날까지 벌어둔 돈 + 이번상담으로 벌돈 P
	}

	// 출력이 paycheck[N]이 아닌이유
	// 마지막날까지 상담을 하지않고도 최고금액을 가져올 수 있기 때문에 
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (answer < paycheck[i]) answer = paycheck[i];
	}
	cout << answer ;

	return 0;
}