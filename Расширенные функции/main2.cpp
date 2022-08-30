#include <iostream>
using namespace std;

int jump(int step) {
    if (step < 0)
        return 0;
    if (step == 0)
        return 1;
    return jump(step - 3) + jump(step - 2) + jump(step - 1);
}

int main() {
    int a;
    cin >> a;
    cout << jump(a);
}