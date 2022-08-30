#include <iostream>
using namespace std;

#define SPRING 0
#define SUMMER 1
#define AUTUMN 2
#define WINTER 3
#define CURRENT_SEASON AUTUMN

int main() {
#if CURRENT_SEASON == 0
    cout << "Spring";
#elif CURRENT_SEASON == 1
    cout << Summer";
#elif CURRENT_SEASON == 2
    cout << "Autumn";
#elif CURRENT_SEASON == 3
    cout << "Winter";
#endif
}