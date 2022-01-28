#include <iostream>
#include <string>
using namespace std;


int main() {

	int N;
	cin >> N;

	string answer = (N % 2) ? "SK" : "CY";
	cout << answer << endl;

	return 0;
}