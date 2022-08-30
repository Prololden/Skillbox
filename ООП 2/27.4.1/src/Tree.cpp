#include "../include/Tree.h"

static int treesCount;

Tree::Tree(bool randomElves)
{
    int bigBranchesCount = rand() % (MAX_BIG_BRANCHES - MIN_BIG_BRANCHES + 1) + MIN_BIG_BRANCHES;
    treesCount++;
    this->id = treesCount;
    std::cout << "Tree # " << treesCount << " is created.\n";
    for (int i = 0; i < bigBranchesCount; ++i)
    {
        BigBranch* bigBranch = new BigBranch(randomElves, i + 1);
        bigBranches.push_back(bigBranch);
    }
}

bool Tree::findElf(std::string elfName)
{
    for (BigBranch* bb : bigBranches)
    {
        if (bb->printElfNeighbours(elfName))
        {
            std::cout << "His address is:\n";
            std::cout << "\t - tree: " << this->id << "\n";
            std::cout << "\t - big branch: " << bb->getId() << "\n";
            return true;
        }
    }
    return false;
}

void Tree::printInfo()
{
    std::cout << " - Tree # " << this->id << " (big branches: " << bigBranches.size() << "):\n";
    for (BigBranch* bb : bigBranches)
    {
        bb->printInfo();
    }

}

Tree::~Tree()
{
    for (BigBranch* bb : bigBranches)
    {
        delete bb;
        bb = nullptr;
    }
    bigBranches.clear();
}