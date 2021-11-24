#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long> trees;

int N, M;
long cut(int a) {
	long result = 0;
	for (int i = 0; i < N; i++) {
		if (trees[i] > a)
			result += (trees[i] - a);
	}
	return result;
}
long b_search(long start, long end) {
	
	long mid = (start + end) / 2;
	
	if (start > end)
		return end;

	if (cut(mid) < M) //�� ���� �߶��� �׷��� ���̸� ª��
		return b_search(start, mid - 1);

	else // �� ���� �ڸ����� ���̸� ���!
		return b_search(mid + 1, end);
}

int main() {
	int temp;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		trees.push_back(temp);
	}
	sort(trees.begin(), trees.end());

	cout << b_search(0, trees.back());

	return 0;
}