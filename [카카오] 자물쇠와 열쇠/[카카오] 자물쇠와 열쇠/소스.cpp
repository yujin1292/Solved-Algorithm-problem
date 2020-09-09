#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N, M;
void print(vector<vector<int>> a) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] == -1)
				cout << ".\t";
			else
				cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-------\n";
}
vector<vector<int>> rotate_key(vector<vector<int>> k) {
	vector<vector<int>> key;

	for (int i = 0; i < M; i++) {
		vector<int> temp;
		for (int j = 0; j < M; j++) {
			temp.push_back(k[M-1-j][i]);
		}
		key.push_back(temp);
	}

	return key;
}
vector<vector<int>> padding(vector<vector<int>> lock_) {
	vector<vector<int>> lock = lock_;
	vector<int> blank;
	for (int i = 0; i < ( N + 2*M ); i++)
		blank.push_back(-1);

	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < M; j++) {
			lock[i].insert(lock[i].begin(), -1);
			lock[i].insert(lock[i].end(), -1);
		}
	}

	for (int i = 0; i < M; i++) {
		lock.insert(lock.begin(), blank);
		lock.insert(lock.end(), blank);
	}

	return lock;

}

bool isFit(int x, int y, vector<vector<int>> key ,vector<vector<int>> lock) {
	//X,Y를 왼쪽끝에 맞춰서 비교
	int count = 0;
	vector<vector<int>> temp = lock;

	for (int i = 0 ; i < key.size()  ; i++) {
		for (int j = 0; j < key.size() ; j++) {
			if (lock[x + i][y + j] == -1) {
				continue;
			}

			if ( (key[i][j] + lock[x + i][y + j]) != 1 ) { //정답아님
				return false;
			}
			else {
				temp[x + i][y + j] = (key[i][j] + lock[x + i][y + j]);
			}
		}
	}
	cout << x << "," << y << endl;
	print(temp);
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < N; j++) {
			if (temp[i+M-1][j+M-1] != 1) {
				return false;
			}
		}
	}

	return true;
}



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	N = lock.size();
	M = key.size();
	bool check = true;
	vector<vector<int>> key_ = key;
	vector<vector<int>> lock_ = padding(lock);
	
	print(lock_);


	for (int rotation = 0; rotation < 4; rotation++) {

		key_ = rotate_key(key_);

		
		for (int i = 0; i < N+M ; i++) {
			for (int j = 0; j < N+M ; j++) {
				if (isFit(i, j, key_, lock_ )) {
					cout << rotation+1<<"번 회전) 아래로 "<< i <<" , 오른쪽으로 " << j<< endl;
					return true;
				}
			}
		}

	}

	return false;
}

int main() {

	vector<vector<int>> key = { {0, 0, 0},{1, 0, 0},{0, 1, 1} };

	vector<vector<int>> lock = { {1, 1, 1},{1, 1, 0},{1, 0, 1}};

	solution(key, lock);
}