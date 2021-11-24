#include <string>
#include <vector>

#define N 12
using namespace std;

int answer = 0;

int vertical[N];
int diagonal[N*2];
int diagonal2[N * 2];

void dfs(int row, int size) {

    if (row + 1 == size) {
        answer++;
        return;
    }

    int nextRow = row + 1;

    for (int i = 0; i < size; i++) {
        if (vertical[i]) continue;
        if (diagonal[nextRow + i]) continue;
        if (diagonal2[nextRow - i + size]) continue;

        vertical[i] = 1;
        diagonal[nextRow + i] = 1;
        diagonal2[nextRow - i + size] = 1;
        dfs(nextRow, size); // nextRow¿¡ ¸» ³ùÀ½

        vertical[i] = 0;
        diagonal[nextRow + i] = 0;
        diagonal2[nextRow - i + size] = 0;
    }
}

int solution(int n) {
    dfs(-1, n);
    return answer;
}

int main() {
    printf("%d", solution(4));
}