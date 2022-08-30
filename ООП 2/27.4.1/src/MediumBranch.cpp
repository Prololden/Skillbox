#include "../include/MediumBranch.h"

MediumBranch::MediumBranch(const std::string elfName, class BigBranch *bigBranch, int id)
{
    assert(bigBranch != nullptr);

    this->id = id;
    this->elfName = elfName;
    this->bigBranch = bigBranch;

    std::cout << "\t\t - Medium branch is created. ";
    if (elfName == "none") std::cout << "No elves are living here.\n";
    else std::cout << elfName << " is living here.\n";
}

std::string MediumBranch::getElfName() const
{
    return this->elfName;
}

void MediumBranch::printInfo()
{
    std::cout << "\t\t - Medium branch # " << this->id << ": ";

    if (this->elfName != "none")
    {
        std::cout << this->elfName << "\n";
    }
    else
    {
        std::cout << "[no elves registered]\n";
    }
}