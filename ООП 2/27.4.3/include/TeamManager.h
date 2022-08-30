#ifndef TASK_27_3_TEAMMANAGER_H
#define TASK_27_3_TEAMMANAGER_H

#include "TeamMember.h"

class TeamManager : public Employee {

private:
    std::vector<TeamMember*> teamMembers;

public:
    TeamManager();
    void work(int task) override;
    std::vector<TeamMember*>* getTeamMembers();
};

#endif //TASK_27_3_TEAMMANAGER_H