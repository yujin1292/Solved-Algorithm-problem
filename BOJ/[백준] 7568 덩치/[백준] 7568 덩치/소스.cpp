#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N , x;
	cin >> N;
	
	vector<int> weight;
	vector<int> hiehgt;
	for (int i = 0; i < N; i++) {
		cin >> x;
		weight.push_back(x);
		cin >> x;
		hiehgt.push_back(x);
	}

	for (int i = 0; i < N; i++) { //Ȯ����ģ��
		int count = 1;
		for (int j = 0; j < N; j++) { //�񱳴��
			if (i == j)
				continue;
			if (weight[i] < weight[j]) 
				if (hiehgt[i] < hiehgt[j])
					count++;
		}
		cout << count << " ";
	}
	cout << endl;
	return 0;
}