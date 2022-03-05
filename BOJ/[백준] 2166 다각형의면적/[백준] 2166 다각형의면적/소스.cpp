#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

int N;

struct _pos
{
	double x;
	double y;

}typedef pos;

vector<pos> point;

double getArea(pos a, pos b, pos c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - (a.y * b.x + b.y * c.x + c.y * a.x);
}

int main() {
	double area = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		pos temp;
		cin >> temp.x;
		cin >> temp.y;
		point.push_back(temp);
	}

	for (int i = 2; i < N; i++) {
		area += getArea(point[0], point[i - 1], point[i]);
	}

	area /= double(2);

	cout << fixed;
	cout.precision(1);
	cout << abs(area) << endl;

	return 0;
}