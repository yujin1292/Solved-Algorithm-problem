#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector< pair< int, pair<int, int> > > info;

bool cmp( pair< int , pair<int, int>> a, pair< int, pair<int, int>> b) {
	
	long Au, Ad; //������ int�� �Ѿ�� long���� ����
	long Bu, Bd;

	Au = a.second.second;
	Ad = a.second.first + a.second.second;
	
	Ad = Ad == 0 ? 1 : Ad; //�и� 0�ϰ�쿡 �񱳰��Ұ��ϴ� 1�� ġȯ

	Bu = b.second.second;
	Bd = b.second.first + b.second.second;

	Bd = Bd == 0 ? 1 : Bd;
	
	long A = Au * Bd; // A�� ������ ����� ����
	long B = Bu * Ad; // B�� ������ ����� ����

	if (A == B) // �������� ���� ���
		return a.first < b.first;
	else
		return B < A;

}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	//�ʱ�ȭ
	for (int i = 0; i < N; i++) { 
		pair< int , pair<int, int> > temp = make_pair( i+1 , make_pair( 0, 0 ));
		info.push_back(temp);
	}

	//����, �������� Ȯ��
	for (int i = 0; i < stages.size(); i++) { 
		int s;
		for (s = 0 ; s < stages[i] -1 ; s++)  //Ŭ������ �����
			info[s].second.first++;

		if (s >= N)
			continue;
		info[s].second.second++;	// ������ �����	
	}

	

	sort(info.begin(), info.end(), cmp);



	//���ĵ� �������� ��ȯ
	for (int i = 0; i < N; i++) {
		answer.push_back(info[i].first);
		cout << info[i].first << "�ܰ� " << info[i].second.second <<" / " <<
			info[i].second.first <<"+"<<info[i].second.second<< endl;
	}

	return answer;
}

