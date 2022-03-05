//Dev - Matching 게임프로그래머 2

#include <string>
#include <vector>

using namespace std;

const int d = 4;
int dr[d] = {1,1,1,0}; // row
int dc[d] = {-1,0, 1,1}; // column 

int solution(int h, int w, int n, vector<string> board) {
    int answer = 0;


    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {

            if (board[i][j] == '0') continue;
            
            for (int dir = 0; dir < d; dir++) {
                int next_x = i;
                int next_y = j;

                int before_x = i - dr[dir];
                int before_y = j - dc[dir];

                if (0 <= before_x && before_x < h) {
                    if (0 <= before_y && before_y < w) {
                        if (board[before_x][before_y] == '1') {
                            continue;
                        }
                    }
                }


                bool finalCheck = true;
                for (int count = 1; count < n; count++) {
                    next_x += dr[dir];
                    next_y += dc[dir];

                    if (next_x < 0 || next_x >= h) {
                        finalCheck = false;
                        break;
                    }
                    if (next_y < 0 || next_y >= w) {
                        finalCheck = false;
                        break;
                    }
                    if (board[next_x][next_y] == '0') {
                        finalCheck = false;
                        break;
                    }
                }


                if (finalCheck) {
                    next_x += dr[dir];
                    next_y += dc[dir];

                    if ((next_x < 0 || next_x >= h) || (next_y < 0 || next_y >= w)) {
                        answer++;
                    }
                    else {
                        if (board[next_x][next_y] == '0') {
                            answer++;
                        }
                    }
                }
               
            }
        }
    }

    return answer;
}