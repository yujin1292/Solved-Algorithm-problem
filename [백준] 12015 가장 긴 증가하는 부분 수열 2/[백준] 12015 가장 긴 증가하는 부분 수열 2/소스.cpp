// ��ó : https://blog.naver.com/mr4454/222521120416

#include <iostream>
#include <vector>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, first, k;
vector <int> vec;

int main(void) {
	fastio;

	cin >> n;
	// ù ���� ������ push
	cin >> first;
	vec.push_back(first);

	// vec �� ���� ���� �������� LIS �� �ƴ�����, ���̴� ����� ���� ������
	for (int i = 1; i < n; i++) {
		cin >> k;
		if (vec.back() >= k) { 
			auto lowerBound = lower_bound(vec.begin(), vec.end(), k);
			*lowerBound = k;
		}
		else {
			vec.push_back(k);
		}
		//for (auto v : vec)
		//	cout << v << " ";
		//cout << endl;
	}

	cout << vec.size();

	return 0;
}