#include <iostream>
#include <deque>
#include <string>
#include <set>

using namespace std;
int hexa2ten(char a) {
	int num = 9;
	switch (a)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return a - '0';

	case 'A' :
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;

	}
}

class Less {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

int find(deque <char> d, int N, int K) {

	int num = N / 4;
	
	set<int,Less> pw;

	for (int i = 0; i < num; i++) { // num 만큼 회전
		// 만들어진 숫자 저장
		int cnt = num;
		int temp = 0;

		for (int j = 0; j < N; j++) {
			
			temp *= 16;
			temp += hexa2ten(d[j]);
			//cout << d[j];

			if (cnt == 1) {

				//cout << " pw : " << temp << endl;
				pw.insert(temp);
				temp = 0;
				cnt = num+1;
			}
			cnt--;
		}

		//rotate
		d.push_front(d.back());
		d.pop_back();

	}

	set<int>::iterator it;
	int cnt = 1;
	int val;
	for (it = pw.begin(); it != pw.end(); it++) {
		if (cnt == K)
			val = *it;
		//cout << cnt <<  " ) value : " << *it << '\n';
		cnt++;
	}

	return val;

}

int main() {

	int testcase;
	
	cin >> testcase;



	for (int t = 0; t < testcase; t++) {
		deque<char> d;
		string temp;
		int N, K;

		cin >> N >> K;
		cin >> temp;

		for (int i = 0; i < N; i++) {
			d.push_back(temp[i]);
		}


		cout << "#" << t + 1 << " " << find(d,N,K) << "\n";

	}
	
}