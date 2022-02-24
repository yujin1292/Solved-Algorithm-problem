#include <iostream>
#include <vector>
using namespace std;

const int MAX_TOWN = 51;
const int INF = 510000;

int arr[MAX_TOWN][MAX_TOWN];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j) continue;
            arr[i][j] = INF;
        }
    }

    for (vector<int> info : road) {
        if (arr[info[0]][info[1]] > info[2]) {
            arr[info[0]][info[1]] = info[2];
            arr[info[1]][info[0]] = info[2];
        }
    }

    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

  
    for (int i = 1; i <= N; i++) {
        if (arr[1][i] <= K) answer++;
    }

    return answer;
}