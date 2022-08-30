#include <iostream>
#include <string>
#include "include/Tree.h"

int main() {
    std::srand(time(nullptr));

    std::vector<Tree*> trees;
    std::cout << "Creating trees...\n";
    Tree* t;
    for (int i = 1; i <= 5; ++i)
    {
        std::cout << "Tree # " << i << ":\n";
        std::cout << "would you like to generate elf names randomly (yes / no)?\n";
        std::string answer;
        std::getline(std::cin, answer);
        t = new Tree(answer == "yes");
        trees.push_back(t);
    }
    std::cout << "------------------------------------------\n\n";
    std::string cmd;
    do
    {
        std::cout << "Please enter the elf name to find\n";
        std::cout << "(\'break\' - to exit | \'info\' - to print village info):\n";
        std::getline(std::cin, cmd);
        if (cmd == "info")
        {
            for (Tree* t : trees)
            {
                t->printInfo();
            }
        }
        else if (cmd != "break")
        {
            bool isFound = false;
            for (Tree* t : trees)
            {
                if (t->findElf(cmd))
                {
                    isFound = true;
                    break;
                }
            }
            if (!isFound) std::cout << "No elf with name \'" << cmd << "\' is found.\n";
        }

    } while (cmd != "break");

    std:: cout << "Program is finishing (deleting trees)...\n";

    //Deleting trees:
    for (Tree* t : trees)
    {
        delete t;
        t = nullptr;
    }
    trees.clear();
    std:: cout << "Program is finished.\n";
    return 0;
}