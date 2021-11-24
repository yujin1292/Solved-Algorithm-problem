#include <string>
#include <vector>

using namespace std;


int GetDayOfWeek(int year, int month, int day)
{
	int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int total_day = 0;

	// �Է��� �ذ� �����̸� 2���� �ϼ��� 29�Ϸ� �����Ѵ�. 
	if (!(year % 4) && ((year % 100) || !(year && 400))) month_days[1] = 29;
	// 1�� 1�� 1�Ϻ��� �Է��� ��-1 ����� �ϼ��� ��� �ջ� 
	total_day += (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	// �Է��� �� - 1 ������ �ϼ��� ��� �ջ� 
	for (int i = 0; i < month - 1; i++) {
		total_day += month_days[i];
	}
	// �Է��� ���� ���ϰ� 7�� ���� 
	return (total_day + day) % 7;
}


string solution(int a, int b) {
	string answer = "";

	string days[] = { "SUN", "MON","TUE","WED","THU","FRI","SAT" };

	int ans = GetDayOfWeek(2016,a , b);
	answer = days[ans];

	return answer;
}