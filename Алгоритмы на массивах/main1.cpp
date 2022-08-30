#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = { -1, 1, -3, 4, -1, 2, 1, -5, 4 };
    int maxSum = a[0];
    int sum = 0;
    int i1, i2;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size() - i; ++j) {
            for (int k = j; k < j + i; ++k) {
                sum += a[k];
            }
            if (sum > maxSum) {
                maxSum = sum;
                i1 = j;
                i2 = j + i - 1;
            }
            sum = 0;
        }
    }

    cout << i1 << " " << i2;

}