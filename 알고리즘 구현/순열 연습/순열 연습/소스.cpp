// next_permutation ����
#include <iostream>     // cout �Լ� ���
#include <algorithm>    // next_permutation �Լ��� sort�Լ� ���

using namespace std;


int Array[5] = { 1,2,3,4,5 };
bool Select[5] = { 0,0,1,1,1 };
bool Select2[5] = { 1,1,1 , 0 ,0 };

int main(void) {

	cout << "���� ��� -------------------\n" ;

	int myints[3] = { 1,2,3 };
	sort(myints, myints + 3); //�������� ����
	do {
		cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
	} while (next_permutation(myints, myints + 3));

	cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';


	cout << "\n3�� �����ϴ� ���� ��� -------------------\n" ;
	do {
		for (int i = 0; i < 5; i++) {
			if (Select[i]) cout << Array[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(Select, Select + 5));
	


	cout << "\n3�� �����ϴ� ���� ��� -------------------\n";

	do {
		for (int i = 0; i < 5; i++) {
			if (Select2[i]) cout << Array[i] << " ";
		}
		cout << "\n";
	} while (prev_permutation(Select2, Select2 + 5)); //prev_permutation Ȱ��


	return 0;
}