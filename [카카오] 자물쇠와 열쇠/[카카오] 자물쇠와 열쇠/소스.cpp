#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N, M;
vector<vector<int>> rotate_key(vector<vector<int>> k) {
	vector<vector<int>> key;
	for (int i = 0; i < M; i++) {
		vector<int> temp;
		for (int j = 0; j < M; j++) 
			temp.push_back(k[M-1-j][i]);	
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
	int count = 0;
	vector<vector<int>> temp = lock;
	for (int i = 0 ; i < key.size()  ; i++) {
		for (int j = 0; j < key.size() ; j++) {
			if (lock[x + i][y + j] == -1) 
				continue;
			
			if ( (key[i][j] + lock[x + i][y + j]) != 1 ) 
				return false;
			else	
				temp[x + i][y + j] = (key[i][j] + lock[x + i][y + j]);
		}
	}

	for (int i = 0; i < N ; i++) 
		for (int j = 0; j < N; j++) 
			if (temp[i+M][j+M] != 1) 
				return false;
	return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	N = lock.size();
	M = key.size();

	vector<vector<int>> key_ = key;
	vector<vector<int>> lock_ = padding(lock);

	for (int rotation = 0; rotation < 4; rotation++) {
		key_ = rotate_key(key_);		
		for (int i = 0; i < N+M ; i++) 
			for (int j = 0; j < N+M ; j++) 
				if (isFit(i, j, key_, lock_ )) 	return true;
	}

	return false;
}






int main() {

	vector<vector<int>> key = { {0, 0, 0},{1, 0, 0},{0, 1, 1} };
	vector<vector<int>> lock = { {1, 1, 1},{1, 1, 0},{1, 0, 1}};
	solution(key, lock);
}