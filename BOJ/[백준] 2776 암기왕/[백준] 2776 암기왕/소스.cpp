#include <iostream>
#include <map>

using namespace std;


map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    int N, M;
    int temp;

    cin >> T;
    while (T--) {
        m.clear();
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            m[temp]++;
        }
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> temp;
            if (m[temp] != 0) cout << "1\n";
            else cout << "0\n";
        }
    }

    return 0;
}