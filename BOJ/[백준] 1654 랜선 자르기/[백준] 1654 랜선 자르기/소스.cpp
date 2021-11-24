#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int K, N;
vector<int> lines;
long cut(long len) {
	long count = 0;
	for (int i = 0; i < K ; i++) 
		count += (lines[i] / len);
	
	return count;
}

long b_search(long start,  long end) {
	long   middle = (start + end) / 2;

	cout << start << " | " << middle << " | " << end << endl;

	if (start >= end) {
		return end;
	}

	if (cut(middle) < N) { //���� �߷ȴٸ� �� ª�� �߶����

		return b_search(start, middle-1);
	}
	else { // �� ��� �߶���

		return b_search(middle+1, end);
	}
}

void solve1() {
	int result, temp;
	sort(lines.begin(), lines.end());
	result = -1;

	for (int i = 1; i <= lines.back(); i++) {
		temp = cut(i);
		if (temp >= N) {
			if (result < i) {
				result = i;
			}
		}
	}

	cout << result << endl;
}

void solve2() {
	sort(lines.begin(), lines.end());
	cout << "gogo!! " << lines.back() << endl;
	cout << b_search(1, lines.back()) << endl;
}

int main() {
	int temp;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		lines.push_back(temp);
	}
	
	//solve1(); //�ð��ʰ�!!
	solve2();

	return 0;
}