#include <iostream>
#include <algorithm>
#define MAX 21

using namespace std;

int N;
int S[MAX][MAX];

int sel[MAX];
int result = 99999999;

void dfs(int count,int index) {
	if (count == N / 2) {
		//  �ɷ�ġ ���� ���
		int gap, start, link;
		start = link = 0;

		for (int i = 0; i < N; i++) {
			if(sel[i])
			for (int j = 0; j < N; j++) {
				if (i == j)
					continue;
				if (sel[j])
					start += S[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			if (!sel[i])
				for (int j = 0; j < N; j++) {
					if (i == j)
						continue;
					if (!sel[j])
						link += S[i][j];
				}
		}
		
		
		if (start < link)
			gap = link - start;
		else
			gap = start - link;

	//	cout << start << " " << link <<" " <<   gap <<endl;
		if (result > gap)
			result = gap;
		return;

	}
	if (index == N)
		return;

	//����
	sel[index] = 1;
	dfs(count + 1, index + 1);
	sel[index] = 0;

	//���þ��ϱ�
	dfs(count, index + 1);

}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> S[i][j];

	dfs(0, 0);
	cout << result << endl;
	return 0;
}