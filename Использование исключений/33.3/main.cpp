#include <iostream>
#include "include/Registry.h"

int main() {
    std::cout << "Data initialization." << "\n";

    std::cout << "=== STRING - STRING test ===\n";
    Registry<std::string, int> reg;

    std::cout << "----------\n- Step 1 -\n";
    reg.add("Lena", 34);
    reg.add("Lena", 34);
    reg.print();

    std::cout << "----------\n- Step 2 -\n";
    Data<std::string, int> d1("Stas", 34);
    reg.add(d1);
    reg.print();

    std::cout << "----------\n- Step 3 -\n";
    reg.remove("Lena");
    reg.print();

    std::cout << "----------\n- Step 4 -\n";
    reg.remove("Stas");
    reg.print();

    std::cout << "----------\n- Step 5 -\n";
    reg.remove("Stas");
    reg.print();

    std::cout << "----------\n- Step 6 -\n";
    reg.add("Stas", 34);
    reg.add("Lena", 34);
    reg.add("Ruslan", 7);
    reg.print();
    auto findResult = reg.find("Ruslan");
    std::cout << findResult->key << " is found.\n";

    std::cout << "=== INT - DOUBLE test ===\n";
    Registry<int, double> reg2;

    std::cout << "----------\n- Step 1 -\n";
    reg2.add(1, 34.7);
    reg2.add(2, 34.3);
    reg2.print();

    std::cout << "----------\n- Step 2 -\n";
    Data<int, double> d2(1, 34.8);
    reg2.add(d2);
    reg2.print();

    std::cout << "----------\n- Step 3 -\n";
    reg2.remove(1);
    reg2.print();

    std::cout << "----------\n- Step 4 -\n";
    reg2.remove(2);
    reg2.print();

    std::cout << "----------\n- Step 5 -\n";
    reg2.remove(2);
    reg2.print();

    std::cout << "----------\n- Step 6 -\n";
    reg2.add(1, 34.1);
    reg2.add(2, 34.7);
    reg2.add(3, 7.4);
    reg2.print();
    auto findResult2 = reg2.find(3);
    std::cout << findResult2->key << " is found.\n";

    return 0;
}