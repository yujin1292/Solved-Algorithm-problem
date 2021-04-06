#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue< int, vector<int>, greater<int> > heap;

	for (int i = 0; i < scoville.size(); i++)
		heap.push(scoville[i]);

	while (!heap.empty()) {

		if (heap.top() >= K)
			heap.pop();
		else {
			if (heap.size() == 1)
				return -1;
			else {
				int temp = heap.top();
				heap.pop();
				temp += (2 * heap.top());
				heap.pop();
				heap.push(temp);
				answer++;
			}
		}
	}


	return answer;
}