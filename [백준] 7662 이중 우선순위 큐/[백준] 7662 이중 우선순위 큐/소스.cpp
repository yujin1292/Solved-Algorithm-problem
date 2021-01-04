#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		int num , number;
		multiset<int> q;
		char c;

		cin >> num;
		for (int ii = 0; ii < num; ii++) {
			cin >> c;
			cin >> number;
			switch (c)
			{
			case 'I':
				q.insert(number);
				break;

			case 'D':
				if (q.size() != 0 ) {
					if (number == -1)  //최솟값 삭제
							q.erase(q.begin());					
					else  //최댓값 삭제
						q.erase(--q.end());				
				}			
				break;
			}
		}
		if (q.size() == 0)
			cout << "EMPTY" << "\n";
		else
			cout << *--q.end()<<" "<< *q.begin() <<"\n";
	}
	return 0;
}

