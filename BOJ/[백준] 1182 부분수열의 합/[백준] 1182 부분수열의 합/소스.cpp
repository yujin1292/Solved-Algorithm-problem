#include <iostream>
#include <vector>

using namespace std;

int N, S;

int const MAX = 21;

int numbers[MAX];
int ans = 0;

void dfs(int v, int cnt, int sum) {

	if (v == N) { // �����ϼ� 
		if (sum == S) { //���� S�� �Ǹ� ���ø���
			if (cnt != 0) { //�������ΰ�?
				ans++;
			}
		}
		return;
	}
	

	dfs(v + 1, cnt, sum); //���þ���
	dfs(v + 1, cnt + 1, sum + numbers[v]); //������

	return;
}


int main() {


	cin >> N >> S;

	// N���� ������ �̷���� ����
	// �κм����߿� ���� S �� ����
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		numbers[i] = temp;
	}

	// �κм��� ã��

	dfs(0, 0, 0);
		
	cout << ans << endl;

}