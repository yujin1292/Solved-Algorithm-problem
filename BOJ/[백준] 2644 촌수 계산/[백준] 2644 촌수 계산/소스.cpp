#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int jockbo[101];
int visitA[101];


void solve(int a, int b) {
	//a�κ����� b �̼�
	int parent;
	queue<int> q;
	int chonA = 0;
	int chonB = 0 ;


	// a root���� Ž��
	q.push(a);
	visitA[a] = 1;
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {

			if (jockbo[q.front()] != 0) {
				q.push(jockbo[q.front()]);
				visitA[jockbo[q.front()]] = 1;
				q.pop();
			}
			else { //Root!
				q.pop();
			}

		}
	}
	
	bool first = true;
	q.push(b);
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {

			//cout << " (b) visit " << q.front() << "\n";
			if (visitA[q.front()] && first) { // A�� �湮�Ѱ���
				parent = q.front();
				first = false;
			//	cout << "find!!" << parent << endl;
			}
			else if (visitA[jockbo[q.front()] ] && first) { // A�� �湮�Ѱ���
				parent = jockbo[q.front()];
				first = false;
			//	cout << "find!!" << parent << endl;
			}

			
			if (jockbo[q.front()] != 0) {
				q.push(jockbo[q.front()]);
				q.pop();
			}
			else { //Root!
				q.pop();
				if (first) {
					cout << "-1\n";
					return;
				}
			}
		}
	}

	int result = 0;

	q.push(a);
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {

			if (q.front() == parent) {
				result += chonA;
				for(int i = 0 ; i < qsize ; i++) // �̼� ��� �������ϱ� ���� ���ֱ� clear
					q.pop();
			}
			
			if (jockbo[q.front()] != 0) {
				q.push(jockbo[q.front()]);
				q.pop();
			}
			else { //Root!
				q.pop();
			}
		}
		chonA++;
	}

	q.push(b);
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {

			if (q.front() == parent) {		
				result += chonB;
				for (int i = 0; i < qsize; i++) //clear
					q.pop();
			}

			if (jockbo[q.front()] != 0) {
				q.push(jockbo[q.front()]);
				q.pop();
			}
			else { //Root!
				q.pop();
			}
		}
		chonB++;
	}


	cout <<result << "\n";

	

}

int main() {
	int family, a, b, edge;

	cin >> family >> a >> b >> edge;

	int t1, t2;

	for (int i = 0; i < edge; i++) { // �Է�
		cin >> t1 >> t2;
		jockbo[t2] = t1; // �ڽ� -> �θ�
	}

	solve(a,b);



	//���

	return 0;
}