#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;
    int fifthNumber;
    int n;

    cin >> n;

    while (n != -2) {
        if (n == -1) {
            for (int i = 0; i < vec.size(); ++i) {
                for (int j = 0; j < vec.size() - 1; ++j) {
                    if (vec[j] > vec[i]) {
                        swap(vec[j], vec[i]);
                    }
                }
            }
            cout << vec[4];
        }
        else {
            vec.push_back(n);
        }
        cin >> n;
    }
}