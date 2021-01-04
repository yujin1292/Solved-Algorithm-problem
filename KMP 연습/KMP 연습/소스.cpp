#include <iostream>
#include <string>
#include <vector>
using namespace std;

int *skip;
string p, t;

vector<int> indexs;

void KMP_Preprocess() {
	int i = 0;
	int j = -1;

	skip[i] = -1;
	while (i < p.size()) {
		while (j >= 0 && p[i] != p[j])
			j = skip[j];
		i++;
		j++;
		skip[i] = j;
	}

}

int KMP_search() {
	int i = 0;
	int j = 0;
	while (i < t.size()) {
		while (j >= 0 && t[i] != p[j]) {
			j = skip[j];
		}
		i++;
		j++;
		if (j == p.size()){
			return ( i - j ); //패턴찾음
			
		}
	}
	return -1; //실패
}


void getSkip() {
	skip = (int*)malloc( sizeof(int) * ( p.size() ) );
	for (int i = 0; i < p.size(); i++)
		skip[i] = 0;

	int j = 0;
	for (int i = 1; i < p.size(); i++) {
		while (j > 0 && p[i] != p[j])
			j = skip[j - 1];

		if (p[i] == p[j])
			skip[i] = ++j;
	}
	for (int i = 0; i < p.size(); i++) 
		cout << p[i] << "|";
	cout << endl;
	for (int i = 0; i < p.size(); i++) {
		cout << skip[i] << "|";
	}
	cout << endl;
}

int main() {
	//getline(cin, t);
	//getline(cin, p);
	p = "abababcaba";
	t = "abzzabxabzzaby";
	
	getSkip();
	
	//KMP_Preprocess();
	//cout << KMP_search();
	
	return 0;
}