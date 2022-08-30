#include "../include/BigBranch.h"
#include <string>

BigBranch::BigBranch(bool randomElves, int id)
{
    this->id = id;
    mediumBranchesCount = rand() % (MAX_MEDIUM_BRANCHES - MIN_MEDIUM_BRANCHES + 1) + MIN_MEDIUM_BRANCHES;
    std::cout << "\t - Big branch was created. It has " << mediumBranchesCount << " medium branches:\n";
    for (int i = 0; i < mediumBranchesCount; ++i)
    {
        std::string elfName;
        if (randomElves)
        {
            elfName = generateRandomName();
        }
        else
        {
            std::cout << "Please enter the elf name: ";
            std::getline(std::cin, elfName);
        }
        MediumBranch* mediumBranch = new MediumBranch(elfName, this, i + 1);
        mediumBranches.push_back(mediumBranch);
    }
}

bool BigBranch::isElfFound(std::string elfName)
{
    for (MediumBranch* mb : mediumBranches)
    {
        if (mb->getElfName() == elfName) return true;
    }
    return false;
}

bool BigBranch::printElfNeighbours(std::string elfName)
{
    if (!isElfFound(elfName))
    {
        return false;
    }
    std::cout << "Elf with name \'" << elfName << "\' has the following neighbours:\n";
    int neighboursCount = 0;
    for (MediumBranch* mb : mediumBranches)
    {
        if (mb->getElfName() != elfName && mb->getElfName() != "none")
        {
            ++neighboursCount;
            std::cout << "\t - " << mb->getElfName() << "\n";
        }
    }
    if (!neighboursCount) std::cout << "\t - no neighbours\n";

    return true;
}

int BigBranch::getId() const
{
    return this->id;
}

void BigBranch::printInfo()
{
    std::cout << "\t - Big branch # " << this->id << " (medium branches: " << mediumBranches.size() << "):\n";
    for (MediumBranch* mb : mediumBranches)
    {
        mb->printInfo();
    }
}

std::string BigBranch::generateRandomName()
{
    char firstLetters[] = {'A', 'E', 'O', 'I', 'U', 'Y'};
    char oddLetters[] = {'a', 'e', 'o', 'i', 'u', 'y'};
    char evenLetters[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'p', 'r', 's', 't'};
    int minLength = 3;
    int maxLength = 7;

    int length = std::rand()%(maxLength - minLength + 1) + minLength;
    if (length == 4)
        return "none";
    else
    {
        char firstChar = firstLetters[std::rand() % (sizeof(firstLetters) / sizeof(char))];
        std::string result {firstChar};
        for (int i = 1; i < length; ++i)
        {
            char letter;
            if (i % 2)
            {
                letter = evenLetters[std::rand() % (sizeof(evenLetters) / sizeof(char))];
            }
            else
            {
                letter = oddLetters[std::rand() % (sizeof(oddLetters) / sizeof(char))];
            }

            result += letter;
        }
        return result;
    }
}

BigBranch::~BigBranch()
{
    for (MediumBranch* mb : mediumBranches)
    {
        delete mb;
        mb = nullptr;
    }
    mediumBranches.clear();
}