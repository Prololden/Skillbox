#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> vec;

    int n;

    cin >> n;

    while (n != -1) {

        vec.push_back(n);

        if (vec.size() > 20) {

            vector<int> newVec(vec.size() - 1);

            for (int i = 1; i <= 20; i++) {

                newVec[i - 1] = vec[i];

            }

            vec = newVec;
        }
        cin >> n;
    }

    for (int i : vec) {

        cout << i << " ";

    }
}