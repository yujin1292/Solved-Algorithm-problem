#include<stdio.h>
#include<algorithm>
#include<queue>
#include <iostream>


using namespace std;

priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

void maxtomin(int a) {
	minheap.push(maxheap.top());
	maxheap.pop();
	maxheap.push(a);
}

void mintomax(int a) {
	maxheap.push(minheap.top());
	minheap.pop();
	minheap.push(a);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; 
	cin >> N;
	int num;

	for (int i = 1; i <= N; i++) {
		cin >> num;
		if (maxheap.size() == 0) {
			maxheap.push(num);
		}
		else if (minheap.size() == 0) {
			if (maxheap.top() > num) maxtomin(num);
			else minheap.push(num);
		}
		else if (minheap.size() > maxheap.size()) {
			if (minheap.top() > num)	maxheap.push(num);
			else mintomax(num);
		}
		else if (maxheap.size() > minheap.size()) {
			if (maxheap.top() >= num) maxtomin(num);
			else  minheap.push(num);
		}
		else { //둘의 사이즈가 같다
			if (minheap.top() > num) maxheap.push(num);
			else mintomax(num);
		}
		cout << maxheap.top() << "\n";
	}
}