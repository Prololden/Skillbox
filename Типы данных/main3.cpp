#include <iostream>
using namespace std;

int main() {
    double delta;
    double speed = 0;
    char text[100];
    sprintf(text, "%.1f km/h\n", speed);
    cout << text;

    cin >> delta;
    speed += delta;
    sprintf(text, "%.1f km/h\n", speed);
    cout << text;
    while (!(speed >= 0 - 0.01 && speed <= 0 + 0.01)) {
        cin >> delta;
        speed += delta;
        if (speed > 150) {
            speed = 150;
        }
        else if (speed < 0) {
            speed = 0;
        }
        sprintf(text, "%.1f km/h\n", speed);
        cout << text;
    }
}