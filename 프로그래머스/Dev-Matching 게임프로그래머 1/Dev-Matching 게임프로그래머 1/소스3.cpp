// Dev-Matching 게임프로그래머 1
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[366];
int lasting[6];

int getDate(string p) {

    int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    long day = 0;
    int yy, mm, dd;
    int i;


    yy = stoi(p.substr(0, 4));
    mm = stoi(p.substr(5, 2));
    dd = stoi(p.substr(8, 2));
    

    if (yy % 4 == 0)
        if (yy % 100 == 0)
            if (yy % 400 == 0)
                m[2] = 29;
            else m[2] = 28;
        else m[2] = 29;
    else m[2] = 28;

    for (i = 1; i <= mm - 1; i++)
        day += m[i];
    day += dd;

    return day;
}

int getCost(string p) {
    int result = 0;
    for (int i = 11; i < p.size(); i++) {
        result *= 10;
        result += (p[i] - '0');
    }
    return result;
}

int getGrade(int cost) {
    if (0 <= cost && cost < 10000) {
        return 0;
    }
    else if (10000 <= cost && cost < 20000) {
        return 1;
    }
    else if (20000 <= cost && cost < 50000) {
        return 2;
    }
    else if (50000 <= cost && cost < 100000) {
        return 3;
    }
    else {
        return 4;
    }
}

vector<int> solution(vector<string> purchase) {
    vector<int> answer;

    for (string p : purchase) {
        int start = getDate(p);
        int cost = getCost(p);

        arr[start] += cost;
  
        int end = start + 30;
        if (end <= 365) {
            arr[end] -= cost;
        }
    }

    int now = -1;
    int date = 1;
    int grade = getGrade(arr[1]);

    //누적합시작
    for (int i = 2; i <= 365; i++) {
        arr[i] += arr[i - 1];   
        int newGrade = getGrade(arr[i]);
        if (grade != newGrade) {
            lasting[grade] += date;
            grade = newGrade;
            date = 0;
        }
        date++;
    }

    lasting[grade] += date;

    for (int i = 0; i <= 4; i++) {
        answer.push_back(lasting[i]);
    }
    return answer;
}