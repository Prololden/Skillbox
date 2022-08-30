#include <iostream>

using namespace std;

void EvenDigits(long long number, int& ans)
{
    if (number == 0) return;

    int digit = number % 10;
    if (digit % 2 == 0) ans++;
    EvenDigits(number / 10, ans);
    return;
}

int main()
{
    int ans = 0;

    EvenDigits(9223372036854775806, ans);

    cout << ans << endl;

    return 0;
}