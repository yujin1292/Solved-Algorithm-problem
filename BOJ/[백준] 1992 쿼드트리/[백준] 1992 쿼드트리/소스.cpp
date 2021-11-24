#include <iostream>
#include <string>
#define MAX 65

using namespace std;

int paper[MAX][MAX];
int N;

string solve(int x, int y, int len){
	//step1 ���̰� 0���� 1���� �˾Ƴ���
	int color = paper[x][y];
	bool isOK = true;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (color != paper[x + i][y + j]) {
				isOK = false;
				break;
			}
		}
		if (isOK == false)
			break;
	}

	//step2 ��������� ��������

	if (isOK) { //��������
		if (color == 0)
			return "0";
		else
			return "1";
	}
	else { //�ɰ��� �����ϱ�
		string result = "(";

		result += solve(x, y, len / 2);
		result += solve(x, y + len / 2, len / 2);
		result += solve(x + len / 2, y, len / 2);
		result += solve(x + len / 2, y + len / 2, len / 2);

		result += ")";

		return result;
	}
}

int main() {

	//�Է�
	cin >> N;
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < N; j++)
			paper[i][j] = (temp[j]-'0');
	}




	cout << solve(0,0,N) << "\n";

	return 0;
}