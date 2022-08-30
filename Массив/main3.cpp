#include <iostream>
#include <cassert>

using namespace std;

float travelTime(float distance, float speed) {
	
	float time;

	assert(speed != 0);
	assert(speed > 0);

	time = distance / speed;
	cout << time;
	return 0;
}

int main() {
	float d;
	float s;
	float result;

	cout << "Enter the distance: ";
	cin >> d;
	cout << "Enter the speed: ";
	cin >> s;

	result = travelTime(d, s);
}