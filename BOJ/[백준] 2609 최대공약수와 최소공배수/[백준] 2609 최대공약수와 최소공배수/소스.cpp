#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	int a, b;
	a = (N < M) ? N : M;
	b = (N < M) ? M : N;


	//�ִ�����
	for (int i = a; i > 0; i--) {
		if (b%i == 0 && a%i == 0) {
			cout << i << "\n";
			break;
		}
	}

	//�ּҰ����
	for (int i = b; ; i++) {
		if ( i%a == 0 && i%b == 0) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}
