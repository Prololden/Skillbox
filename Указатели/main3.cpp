#include <iostream>
using namespace  std;

bool substr(char* str1, char* str2) {
    bool found = true;
    for (int i = 0; *(str1 + i) != '\0'; ++i) {
        if (*(str1 + i) == (*str2)) {
            for (int j = 0; *(str2 + j) != '\0'; ++j) {
                if (*(str2 + j) != *(str1 + i + j)) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char* a = "Hello world";
    char* b = "wor";
    char* c = "banana";

    cout << substr(a, b) << " " << substr(a, c);
}