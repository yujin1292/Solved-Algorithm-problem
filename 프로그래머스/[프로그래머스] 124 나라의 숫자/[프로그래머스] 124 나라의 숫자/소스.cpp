#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n) {
    string answer = "";

    int num = n;
    stack<int> s;
    
    while (num) {
        int digit = num % 3;
        if (digit == 0) {
            digit = 4;
            num--;
        }
        answer.insert(answer.begin(), (digit + '0'));
        num /= 3;
    }

    return answer;
}
