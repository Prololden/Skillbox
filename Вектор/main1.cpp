#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    int del;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cin >> del;

    for (auto i = v.begin(); i != v.end();) {
        if (*i == del) {
            v.erase(i);
        }
        else {
            i++;
        }
    }

    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
}