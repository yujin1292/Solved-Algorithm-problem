#include <iostream>
#include <vector>

using namespace std;

long ans = 0;

long N; //������ ��
vector<int> classroom;

long B; // �Ѱ�����  �ѽ����忡 �����Ҽ��ִ� �����ڼ�
long C; // �ΰ������� �����Ҽ��ִ� ��

	   //�Ѱ����� �Ѹ�, �ΰ������� ������


void solve() {

	for (long i = 0; i < N; i++) {
		classroom[i] -= B; // �Ѱ������� �����ϴ°� �ٻ�����
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