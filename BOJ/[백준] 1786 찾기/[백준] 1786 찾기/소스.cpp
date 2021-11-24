#include <iostream>
#include <string>
#include <vector>
using namespace std;

int *skip;
string p, t;

vector<int> indexs;

void getSkip() {
	skip = (int*)malloc(sizeof(int) * (p.size()));
	for (int i = 0; i < p.size(); i++)
		skip[i] = 0;

	int j = 0;
	for (int i = 1; i < p.size(); i++) {
		while (j > 0 && p[i] != p[j])
			j = skip[j - 1];

		if (p[i] == p[j])
			skip[i] = ++j;
	}
	
}

void KMP() {
	int j = 0;
	for (int i = 0; i < t.size() ; i++) {
		while (j > 0 && t[i] != p[j])
			j = skip[j - 1];
		if (t[i] == p[j]) {
			if (j == p.size() - 1) {
				indexs.push_back(i - p.size() +2);
				j = skip[j];
			}
			else
				j++;
		}
	}
}

int main() {
	getline(cin, t);
	getline(cin, p);
	
	getSkip();
	KMP();
	cout << indexs.size() << endl;
	for (int i = 0; i < indexs.size(); i++) 
		cout << indexs[i] << " ";
	
	return 0;
}
