#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {

	vector<int> basket;

	
	int depth = board.size();
	int count = 0;

	for (int n = 0; n < moves.size(); n++) {
		int dir = moves[n] -1;

		for (int i = 0; i < depth; i++) {
			
			if (board[i][dir] == 0) //빈공간임
				continue;

			if (!basket.empty()) { //뭔가 들어있으면 확인해봐
				if (basket.back() == board[i][dir]) { // 같은게 만났어
					basket.pop_back(); //없애
					count+=2; //개수세고
					board[i][dir] = 0;
				}
				else { //들어있는데 터트리지않음
					basket.push_back(board[i][dir]);
					board[i][dir] = 0;
				}
			}
			else { //비어있으면 그냥 넣는거지
				basket.push_back(board[i][dir]);
				board[i][dir] = 0;
			}


			break;
		}

	}
	

	

	return count;
}