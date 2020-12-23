#include <iostream>
#include <string>

using namespace std;

string p = "hola";
int skip[4];
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

string t = "hehollallogoodmorningholoas";
int KMP_search() {
	int i = 0;
	int j = 0;
	while (i < t.size()) {
		while (j >= 0 && t[i] != p[j]) {
			j = skip[j];
		}
		i++;
		j++;
		if (j == p.size()-1)
			return i - j; //패턴찾음
	}
	return -1; //실패
}


int main() {

	KMP_Preprocess();
	for (int i = 0; i < 4; i++)
		cout << skip[i] << " ";
	cout << endl;
	cout << KMP_search();

	//string t = "helloimyujineyosoyjin";
	//string p = "soy";

	//for (int i = 0; i < t.size(); i++) {
	//	bool isFinded = true;
	//	for (int j = 0; j < p.size(); j++) {
	//		if (t[i + j] != p[j]) //불일치
	//			isFinded = false;
	//	}
	//	if (isFinded) {
	//		cout << i << "--> find!!\n";
	//		break;
	//	}
	//}
	//

	//int i = 0;
	//int j = 0;

	//while (j < p.size() && i < t.size()) {
	//	if (t[i] != p[j]) {
	//		i = i - j;
	//		j = -1;
	//	}
	//	i++;
	//	j++;
	//}
	//if (j == p.size())
	//	cout << i - p.size() << endl;
	//else
	//	cout <<  i << endl;





	return 0;
}