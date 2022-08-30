#ifndef TASK_27_3_TEAMMEMBER_H
#define TASK_27_3_TEAMMEMBER_H

#include "Employee.h"

class TeamMember : public Employee {

private:
    TaskType taskType {NO_TASK};

public:
    TeamMember();
    void work(int taskType) override;
    TaskType getTaskType();
};

#endif //TASK_27_3_TEAMMEMBER_H