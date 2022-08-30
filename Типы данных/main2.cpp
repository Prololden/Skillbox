#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string str = "";
    str = to_string(a) + "." + to_string(b);
    cout << str;
}