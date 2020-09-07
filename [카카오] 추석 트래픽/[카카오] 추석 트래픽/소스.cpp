#include <string>
#include <vector>

using namespace std;
struct Timetable {
	int endtime;
	int process_time;
};
int solution(vector<string> lines) {

	string hour, min, sec, milisec;
	string proc_sec;
	int answer = 0, temp_answer = 0;
	Timetable timetable[2000];
	for (int i = 0; i < lines.size(); i++) {
		hour = lines[i].substr(11, 2);
		min = lines[i].substr(14, 2);
		sec = lines[i].substr(17, 2);
		milisec = lines[i].substr(20, 3);
		timetable[i].endtime = (stoi(hour) * 1000 * 3600) + (stoi(min) * 60 * 1000) + (stoi(sec) * 1000) + stoi(milisec);

		proc_sec = lines[i].substr(24, lines[i].size() - 24);
		double proc_milisec = stod(proc_sec);
		timetable[i].process_time = proc_milisec * 1000 ;
	}


	int fur_time, next_start_time;
	for (int i = 0; i < lines.size(); i++) {
		temp_answer = 0;
		fur_time = timetable[i].endtime + 1000;
		for (int j = i + 1; j < lines.size(); j++) {
			next_start_time = timetable[j].endtime - timetable[j].process_time + 1;
			if (next_start_time < fur_time) {
				temp_answer++;
				continue;
			}
			// break;
		}
		if (temp_answer > answer) {
			answer = temp_answer;
		}
	}
	return answer + 1;
}