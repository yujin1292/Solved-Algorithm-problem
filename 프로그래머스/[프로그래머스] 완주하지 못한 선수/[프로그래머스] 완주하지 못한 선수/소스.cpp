#include <string>
#include <vector>
#include <map>


using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> partici;
	map<string, int> comple;

	for (int i = 0; i < participant.size(); i++)
		partici[participant[i]]++;

	for (int i = 0; i < completion.size(); i++)
		comple[completion[i]]++;


	for (map<string, int>::iterator iter = partici.begin(); iter != partici.end(); iter++)
		if (iter->second != comple[iter->first])
			answer += iter->first;

	return answer;
}
