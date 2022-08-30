#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int getTypeOfRequest(string request) {
    if (request.find(' ') != string::npos) return 1;
    if (isdigit(request[0])) return 2;
    else return 3;
}

int main() {
    map<string, string> phoneName;
    map<string, vector<string>> namePhones;
    string phone = "";
    string surname = "";
    string request;

    phoneName.insert(make_pair<string, string>("69-70-30", "Ivanov"));
    phoneName.insert(make_pair<string, string>("69-70-30", "Ivanov"));
    namePhones.insert(make_pair<string, vector<string>>("Ivanov", vector<string>()));
    namePhones["Ivanov"].push_back("69-79-30");
    phoneName.insert(make_pair<string, string>("69-72-31", "Ivanov"));
    namePhones["Ivanov"].push_back("69-72-31");

    cout << "Enter the request\n";

    getline(cin, request);

    switch (getTypeOfRequest(request)) {
    case 1: {
        phone = request.substr(0, request.find(' '));
        surname = request.substr(request.find(' ') + 1, request.length());

        auto item = namePhones.find(surname);
        phoneName.insert(make_pair(phone, surname));
        if (item == namePhones.end()) {
            namePhones.insert(make_pair(surname, vector<string>() = { phone }));
        }
        else {
            namePhones[item->first].push_back(phone);
        }
        cout << "Done!";
        break;
    }
    case 2: {
        auto item = phoneName.find(request);
        cout << item->second << endl;
        break;
    }
    case 3: {
        auto item = namePhones.find(request);
        for (int i = 0; i < item->second.size(); i++) {
            cout << item->second[i] << " ";
        }
        break;
    }
    }
}