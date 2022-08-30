#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    ofstream file("pic.txt");
    if (!file.is_open()) {
        cout << "Could not open the file\n";
        return 0;
    }
    srand(time(nullptr));
    int width;
    int height;
    cout << "Enter width and height of the picture\n";
    cin >> width >> height;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            file << rand() % 2;
        }
        file << "\n";
    }
}