#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector< pair< int, pair<int, int> > > info;

bool cmp( pair< int , pair<int, int>> a, pair< int, pair<int, int>> b) {
	
	long Au, Ad; //범위가 int를 넘어서서 long으로 선언
	long Bu, Bd;

	Au = a.second.second;
	Ad = a.second.first + a.second.second;
	
	Ad = Ad == 0 ? 1 : Ad; //분모가 0일경우에 비교가불가하니 1로 치환

	Bu = b.second.second;
	Bd = b.second.first + b.second.second;

	Bd = Bd == 0 ? 1 : Bd;
	
	long A = Au * Bd; // A의 실패율 통분한 분자
	long B = Bu * Ad; // B의 실패율 통분한 분자

	if (A == B) // 실패율이 같을 경우
		return a.first < b.first;
	else
		return B < A;

}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	//초기화
	for (int i = 0; i < N; i++) { 
		pair< int , pair<int, int> > temp = make_pair( i+1 , make_pair( 0, 0 ));
		info.push_back(temp);
	}

	//실패, 성공여부 확인
	for (int i = 0; i < stages.size(); i++) { 
		int s;
		for (s = 0 ; s < stages[i] -1 ; s++)  //클리어한 사람수
			info[s].second.first++;

		if (s >= N)
			continue;
		info[s].second.second++;	// 실패한 사람수	
	}

	

	sort(info.begin(), info.end(), cmp);



	//정렬된 스테이지 반환
	for (int i = 0; i < N; i++) {
		answer.push_back(info[i].first);
		cout << info[i].first << "단계 " << info[i].second.second <<" / " <<
			info[i].second.first <<"+"<<info[i].second.second<< endl;
	}

	return answer;
}

