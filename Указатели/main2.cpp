#include <iostream>
using namespace  std;

void reversePtrNumbers(int* iPtr) {
    for (int i = 0; i < 5; ++i) {
        int temp;
        temp = *(iPtr - i);
        *(iPtr - i) = *(iPtr + i - 9);
        *(iPtr + i - 9) = temp;
    }
}

int main() {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* iPtr;

    for (int i = 0; i < 10; ++i) {
        iPtr = (arr + i);
    }
    cout << "Initial pointer numbers: " << endl;
    for (int i = 0; i < 10; ++i) {
        cout << *(iPtr - i) << endl;
    }

    reversePtrNumbers(iPtr);
    cout << "Reversed pointer numbers: " << endl;
    for (int i = 0; i < 10; ++i) {
        cout << *(iPtr - i) << endl;
    }
}