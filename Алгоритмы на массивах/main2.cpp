#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = { 11, 15, 2, 7 };
    int res = 9;
    int sum;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            if ((sum = a[i] + a[j]) == res) {
                cout << a[i] << " " << a[j];
                return 0;
            }
        }
    }
}