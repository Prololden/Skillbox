#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("state.txt", ios::app);
    if (!file.is_open()) {
        cout << "Could not open the file\n";
        return 0;
    }
    string name;
    string surname;
    string date;
    int cash;
    cout << "Enter the data in format [First name] [Second name] [DD.MM.YYYY] [Amount of money]\n";
    cin >> name >> surname >> date >> cash;

    while (stoi(date.substr(0, 2)) < 1 
        || stoi(date.substr(0, 2)) > 31
        || stoi(date.substr(3, 2)) < 1 
        || stoi(date.substr(3, 2)) > 31
        || stoi(date.substr(6, 4)) < 1) {
        cout << "Invalid data. Try again.\n";
        cin >> name >> surname >> date >> cash;
    }

    file << name << " " << surname << " " << date << " " << cash << "\n";
    file.close();
}