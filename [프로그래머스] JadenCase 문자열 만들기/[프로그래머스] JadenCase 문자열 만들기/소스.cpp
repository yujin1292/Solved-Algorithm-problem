#include <string>
#include <vector>

using namespace std;

int gap = 'A' - 'a';
bool isLowcase(char c) {
    return 'a' <= c && c<='z';
}
bool isCapital(char c) {
    return 'A' <= c && c <= 'Z';
}

string solution(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 &&  isLowcase(s[0]) ) s[0] = s[0] + gap;
        if (s[i] == ' ') {
            if (i + 1 < s.size() && isLowcase(s[i+1]) ) {
                s[i + 1] = s[i + 1] + gap;
            }
        }
        else {
            if (i + 1 < s.size() && isCapital(s[i + 1])) {
                s[i + 1] = s[i + 1] - gap;
            }
        }
    }
    return s;
}