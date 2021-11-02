#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, S;
long long result;

vector<int> numbers;
vector<int> leftSum;
vector<int> rightSum;

void makeSumArray(int idx, int end, int sum , vector<int> &v) {
	if (idx ==end) {
		v.push_back(sum);
		return;
	}

	// cur +1 선택
	makeSumArray(idx + 1, end, sum + numbers[idx] , v);
	// cur + 1 선택안함
	makeSumArray(idx + 1, end, sum , v);
}

bool cmp(int a, int b) { return a < b; }
int main() {

	int temp;
	cin >> N >> S;

	for (int i = 1; i <= N; i++) {
		cin >> temp;
		numbers.push_back(temp);
	}

	makeSumArray(0,  N/2 , 0, leftSum);
	makeSumArray(N/2, N,   0, rightSum);

	sort(leftSum.begin(), leftSum.end(), cmp);
	sort(rightSum.begin(), rightSum.end(), cmp);


	int left = 0;
	int right = rightSum.size() - 1;

	while (left < leftSum.size() && right >= 0) {
		int lValue = leftSum[left];
		int rValue = rightSum[right];

		if (lValue + rValue == S) {
			// 중복값이 있을수있기때문에 체크 
			long long lcnt = 0;
			while (left < leftSum.size() && leftSum[left] == lValue) {
				left++;
				lcnt++;
			}

			long long rcnt = 0;
			while (right >= 0 && rightSum[right] == rValue) {
				right--;
				rcnt++;
			}
			result += lcnt * rcnt;
		}

		if (lValue + rValue > S) {
			right--;
		}

		if (lValue + rValue < S) {
			left++;
		}
	}


	if (S == 0) result--;
	cout << result;

	return 0;
}