#ifndef TASK_27_1_TREE_H
#define TASK_27_1_TREE_H

#include "BigBranch.h"


class Tree {

private:
    const int MAX_BIG_BRANCHES = 5;
    const int MIN_BIG_BRANCHES = 3;
    std::vector<BigBranch*> bigBranches;
    int id;

public:
    Tree(bool randomElves);
    ~Tree();


    bool findElf(std::string elfName);


    void printInfo();
};

#endif