#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int solution(vector<string> words) {
	int answer = 0;
	int maxlength = 0;

	int* visit = (int*)malloc(sizeof(int)* words.size());
	//초기화
	for (int i = 0; i < words.size(); i++)
		visit[i] = 0;


	sort(words.begin(), words.end());

	for (int i = 0; i < words.size(); i++)
		if (maxlength < words[i].size())
			maxlength = words[i].size();

	for (int i = 0; i < maxlength + 1; i++) {

		for (int w = 0; w < words.size(); w++) {

			if (visit[w])
				continue;
			if (words[w].size() == i) {
				answer += i;
				visit[w] = 1;
				continue;
			}


			bool isIn = false;

			string substring = words[w].substr(0, i + 1);
			for (int c = w - 1; c <= w + 1; c += 2) {
				if (0 <= c && c < words.size()) {
					if (visit[c])
						continue;
					if (words[c].substr(0, i + 1) == substring) {
						isIn = true; //중복되는게있음
						break;
					}
				}
				
			}

			if (!isIn) { //중복없음
				answer += (i + 1);
				visit[w] = 1;
			}
		}
	}



	return answer;
}