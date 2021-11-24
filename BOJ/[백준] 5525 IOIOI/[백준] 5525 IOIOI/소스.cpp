#include <iostream>
#include <string>

using namespace std;

int N, M;
string s;
int val[1000001];

int main() {
	int result = 0;
	cin >> N >> M >>s;
	for (int i = 0; i < M; i++) {
		
		if (s[i] == 'I') {

			if (i - 1 >= 0 && s[i - 1] == 'O') {
				//앞이 P(n-1)인가?
				if (i-2>=0 && s[i - 2] == 'I') {
					val[i] = val[i - 2] + 1;
					if (val[i] >= N)
						result++;
				}
			}
		}
	}

	cout << result << endl;

	return 0;
}