#include <iostream>
#include <algorithm>

using namespace std;

// paycheck[i] : i�ϱ��� ����� ��ġ�� i�Ͽ� ����� �� �ݾ�
int paycheck[16];

int main() {

	int N, t, p;
	cin >> N;

	for (int day = 1; day <= N; day++) {
		cin >> t >> p;

		// ����� ������ ��ĥ �� ���� ���� ������� �ʴ´�.
		if (day + t - 1 > N) continue;


		// ��� ������ ���� ����� �ְ�ݾ��� �����´�
		int before = 0;
		for (int i = 1; i < day; i++) {
			if (before < paycheck[i]) before = paycheck[i];
		}

		// �ش� ����� ������ ��( day + t - 1 )
		paycheck[day + t - 1] = max( before + p , paycheck[day + t - 1]);
		// �ش� ����� �����Ѵ�  -> paycheck[day+t-1] = paycheck[day+t-1]  (��������)
		// �ش� ����� �����Ѵ�  -> paycheck[day+t-1] = day �������� ����� �� + �̹�������� ���� P
	}

	// ����� paycheck[N]�� �ƴ�����
	// ������������ ����� �����ʰ� �ְ�ݾ��� ������ �� �ֱ� ������ 
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (answer < paycheck[i]) answer = paycheck[i];
	}
	cout << answer ;

	return 0;
}