#include <iostream>
using namespace std;

int jump(int n, int k = 3) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    int ways = 0;
    for (int i = k; i > 0; --i) {
        ways += jump(n - i, k);
    }
    return;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << jump(a, b);
}