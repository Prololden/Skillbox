#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = { -100,-50, -5, 1, 10, 15 };

    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size() - i - 1; ++j) {
            int abs1 = abs(a[j]);
            int abs2 = abs(a[j + 1]);

            if (abs1 > abs2) {
                swap(a[j], a[j + 1]);
            }
        }
    }

    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
}