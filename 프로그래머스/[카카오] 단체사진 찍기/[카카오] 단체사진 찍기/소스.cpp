#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<char> result;
vector<string> datas;
int N;


int visit[8];
char friends1[] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

int val = 0;

void check() {
	for (int i = 0; i < N; i++) {

		char a = datas[i][0];
		char b = datas[i][2];
		char op = datas[i][3];
		int gap = datas[i][4] - '0';

		int indexA, indexB;

		for (int j = 0; j < 8; j++) {
			if (result[j] == a)
				indexA = j;
			if (result[j] == b)
				indexB = j;
		}


		int cal = indexA < indexB ? indexB - indexA : indexA - indexB;
		cal--;


		if (op == '=') {
			if (cal != gap)
				return;
		}
		else if (op == '<') { // �̸�
			if (cal >= gap)
				return;
		}
		else {//�ʰ�
			if (cal <= gap)
				return;
		}
	}
	val++;
}

void dfs(int v, int count) {
	visit[v] = 1;

	if (count == 8) {
		check();
		return;
	}

	for (int i = 0; i < 8; i++) {
		if (visit[i] == 1) { //�����Ѱ�� �ǳʶ�
			continue;
		}

		else {
			result.push_back(friends1[i]);
			dfs(i, count + 1);

			//���󺹱�
			visit[i] = 0;
			result.pop_back();
		}

	}
}


int solution(int n, vector<string> data) {
	//�������� �ʱ�ȭ
	datas = data;
	N = n;
	val = 0;
	for (int i = 0; i < 8; i++)
		visit[i] = 0;


	// ��� ����
	for (int i = 0; i < 8; i++) {
		result.push_back(friends1[i]);
		dfs(i, 1);
		visit[i] = 0;
		result.pop_back();
	}

	return val;
}