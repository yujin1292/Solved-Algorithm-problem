#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp[1000001];


int get(int X) {

    if (X == 1) return 0;
    
    if (dp[X].size() == 0) {
        int a, b, c;

        if (X % 2 == 0) a = get(X / 2);
        else a = X + 1;

        if (X % 3 == 0)   b = get(X / 3);
        else b = X + 1;
        
        c = get(X - 1);

        if (a < b) {
            if (c < a) {
                dp[X - 1].insert(dp[X - 1].begin(), X - 1);
                dp[X] = dp[X - 1];
                dp[X - 1].erase(dp[X - 1].begin());
            }
            else {
                dp[X/2].insert(dp[X/2].begin(), X/2);
                dp[X] = dp[X/2];
                dp[X/2].erase(dp[X/2].begin());
            }

        }
        else {
            if (c < b) {
                dp[X - 1].insert(dp[X - 1].begin(), X - 1);
                dp[X] = dp[X - 1];
                dp[X - 1].erase(dp[X - 1].begin());
            }
            else {
                dp[X / 3].insert(dp[X / 3].begin(), X / 3);
                dp[X] = dp[X / 3];
                dp[X / 3].erase(dp[X / 3].begin());
            }
        }
        
        return dp[X].size();
    }
    else  return dp[X].size();
}

int main() {

    int X;
    cin >> X;

    get(X);
    cout << dp[X].size() << endl;
    cout << X << " ";
    for (int i = 0; i < dp[X].size(); i++) {
        cout << dp[X][i] << " ";
    }

    return 0;
}