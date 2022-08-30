#ifndef TASK_27_1_BIGBRANCH_H
#define TASK_27_1_BIGBRANCH_H

#include "MediumBranch.h"
#include <vector>
#include <random>

class BigBranch {

private:
    const int MIN_MEDIUM_BRANCHES = 2;
    const int MAX_MEDIUM_BRANCHES = 3;
    std::vector<MediumBranch*> mediumBranches;
    int mediumBranchesCount;
    int id;


    std::string generateRandomName();


    bool isElfFound(std::string elfName);

public:
    BigBranch(bool randomElves, int id);
    ~BigBranch();


    bool printElfNeighbours(std::string elfName);


    int getId() const;

    void printInfo();
};

#endif