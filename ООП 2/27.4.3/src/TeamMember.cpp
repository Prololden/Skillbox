#include "../include/TeamMember.h"

TeamMember::TeamMember()
{
    this->position = TEAM_MEMBER;
}

void TeamMember::work(int taskType)
{
    this->taskType = TaskType (taskType);
    std::cout << "\t\t\t- Team member #" << this->id << ": I've received task type - " << getTaskTypeString(this->taskType) << "\n";
}

TaskType TeamMember::getTaskType() {
    return this->taskType;
}