#include <iostream>

using namespace std;

int main() {

	string Surname[10];
	int n;
	for (int i = 0; i < 10; i++) {
		cin >> Surname[i];
	}

	for (int i = 0; i < 4; i++) {

		cin >> n;
		if (n < 10) {
			cout << Surname[i] << endl;
		}
		else {
			cout << "Такой квартиры нету !!!";
			break;
		}
	}
}