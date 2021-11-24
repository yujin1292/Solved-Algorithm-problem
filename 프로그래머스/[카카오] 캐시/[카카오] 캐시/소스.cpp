#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<int, string> > cache;

int answer;
int ttime;

bool cmp(pair<int, string>a, pair<int, string> b) {
	return b.first < a.first;
}

bool check( string c , int cacheSize ) {
	if (cacheSize == 0) //교체할게없음 언제나 fault
		return false;

	for (int i = 0; i < cache.size(); i++) {
		if (cache[i].second == c) { //hit
			//시간 업데이트
			cache[i].first = ttime;
			sort(cache.begin(), cache.end(), cmp );
			return true;
		}

	}
	return false; //miss
}

void change( string c , int cacheSize ) {
	//맨뒤가 제일 오래됐음
	if (cacheSize == 0) //교체할게없음
		return;

	if (cache.size() == cacheSize) {
		cache.pop_back();
	}
	cache.push_back({ ttime,c});
	sort(cache.begin(), cache.end(), cmp);

}


void print() {

	for (int i = 0; i < cache.size(); i++) 
		cout << cache[i].first << " : " << cache[i].second << endl;

	cout << "---------\n";
}
string lower(string s) {
	string temp;
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			temp.insert(temp.end(), s[i] - ('A' - 'a'));
		else
			temp.insert(temp.end(), s[i]);
	}

	return temp;
}
int solution(int cacheSize, vector<string> cities) {
	answer = ttime = 0;

	
	for (int i = 0; i < cities.size(); i++) {
		string s = lower(cities[i]);

		if (!check(s , cacheSize)) {// fault
		//	cout << s << " fault!\n" << endl;
			change(s, cacheSize); //캐시교체
			answer += 5;
		}
		else {

		//	cout << s << " hit !\n" << endl;
			answer += 1;
		}
	
		//print();
		ttime++;
	}


	return answer;

}


int main() {
	vector<string> temp = {
			"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo",
			"Seoul", "NewYork", "LA"
	};

	cout << solution(3, temp);

}