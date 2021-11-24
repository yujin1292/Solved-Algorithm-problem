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
			
			if (board[i][dir] == 0) //�������
				continue;

			if (!basket.empty()) { //���� ��������� Ȯ���غ�
				if (basket.back() == board[i][dir]) { // ������ ������
					basket.pop_back(); //����
					count+=2; //��������
					board[i][dir] = 0;
				}
				else { //����ִµ� ��Ʈ��������
					basket.push_back(board[i][dir]);
					board[i][dir] = 0;
				}
			}
			else { //��������� �׳� �ִ°���
				basket.push_back(board[i][dir]);
				board[i][dir] = 0;
			}


			break;
		}

	}
	

	

	return count;
}