#include <iostream>
using namespace std;

void initialization(bool pimple[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            pimple[i][j] = true;
        }
    }
}

bool print_and_check_pimple(bool pimple[][12]) {
    bool empty = true;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {

            if (pimple[i][j]) {
                cout << "o ";
                empty = false;
            }
            else {
                cout << "x ";
            }
        }
        cout << endl;
    }

    return empty;
}

void poping(bool pimple[][12], int startX, int startY, int endX, int endY) {
    int startPointX;
    int startPointY;
    int endPointX;
    int endPointY;
    if (startX <= endX) {
        startPointX = startX;
        endPointX = endX;
    }
    else {
        startPointX = endX;
        endPointX = startX;
    }
    if (startY <= endY) {
        startPointY = startY;
        endPointY = endY;
    }
    else {
        startPointY = endY;
        endPointY = startY;
    }
    for (int i = startPointY; i <= endPointY; i++) {
        for (int j = startPointX; j <= endPointX; j++) {
            pimple[i][j] = false;
            cout << "Pop!\n";
        }
    }

}

int main() {
    bool pimple[12][12];
    initialization(pimple);
    int startX;
    int startY;
    int endX;
    int endY;
    while (!print_and_check_pimple(pimple)) {
        cout << "Enter the start koordinats:";
        cin >> startX >> startY;
        cout << "Enter the koordinats below the start one:";
        cin >> endX >> endY;

        if (startX < 1 || startX > 12 || startY < 1 || startY > 12
            || endX < 1 || endX > 12 || endY < 1 || endY > 12) {
            cout << "Invalid range!\n";
        }
        else {
            poping(pimple, --startX, --startY, --endX, --endY);
        }
    }
    cout << "Done!";
}