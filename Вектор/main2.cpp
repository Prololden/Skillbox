#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<float> price = { 2.5, 4.25, 3.0, 10.0 };
    vector<int> purchases = { 1, 1, 0, 3 };

    float sum = 0;

    for (int i : purchases) {
        sum += price[i];
    }
    cout << sum;
}