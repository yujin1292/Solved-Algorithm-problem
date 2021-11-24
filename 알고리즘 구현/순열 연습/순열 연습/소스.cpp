// next_permutation 예시
#include <iostream>     // cout 함수 사용
#include <algorithm>    // next_permutation 함수와 sort함수 사용

using namespace std;


int Array[5] = { 1,2,3,4,5 };
bool Select[5] = { 0,0,1,1,1 };
bool Select2[5] = { 1,1,1 , 0 ,0 };

int main(void) {

	cout << "순열 출력 -------------------\n" ;

	int myints[3] = { 1,2,3 };
	sort(myints, myints + 3); //오름차순 정렬
	do {
		cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
	} while (next_permutation(myints, myints + 3));

	cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';


	cout << "\n3개 선택하는 조합 출력 -------------------\n" ;
	do {
		for (int i = 0; i < 5; i++) {
			if (Select[i]) cout << Array[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(Select, Select + 5));
	


	cout << "\n3개 선택하는 조합 출력 -------------------\n";

	do {
		for (int i = 0; i < 5; i++) {
			if (Select2[i]) cout << Array[i] << " ";
		}
		cout << "\n";
	} while (prev_permutation(Select2, Select2 + 5)); //prev_permutation 활용


	return 0;
}