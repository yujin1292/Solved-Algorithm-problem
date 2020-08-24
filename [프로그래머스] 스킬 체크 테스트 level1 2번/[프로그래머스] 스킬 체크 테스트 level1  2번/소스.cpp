#include <string>
#include <vector>

using namespace std;


int GetDayOfWeek(int year, int month, int day)
{
	int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int total_day = 0;

	// 입력한 해가 윤년이면 2월의 일수를 29일로 변경한다. 
	if (!(year % 4) && ((year % 100) || !(year && 400))) month_days[1] = 29;
	// 1년 1월 1일부터 입력한 해-1 년까지 일수를 모두 합산 
	total_day += (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	// 입력한 달 - 1 까지의 일수를 모두 합산 
	for (int i = 0; i < month - 1; i++) {
		total_day += month_days[i];
	}
	// 입력한 일을 합하고 7로 나눔 
	return (total_day + day) % 7;
}


string solution(int a, int b) {
	string answer = "";

	string days[] = { "SUN", "MON","TUE","WED","THU","FRI","SAT" };

	int ans = GetDayOfWeek(2016,a , b);
	answer = days[ans];

	return answer;
}