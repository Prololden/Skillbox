#ifndef TASK_27_1_MEDIUMBRANCH_H
#define TASK_27_1_MEDIUMBRANCH_H

#include <iostream>
#include <cassert>

class BigBranch;

class MediumBranch {

private:
    std::string elfName {"unknown"};
    BigBranch* bigBranch {nullptr};
    int id;

public:
    MediumBranch(const std::string elfName, class BigBranch* bigBranch, int id);


    std::string getElfName() const;


    void printInfo();
};

#endif