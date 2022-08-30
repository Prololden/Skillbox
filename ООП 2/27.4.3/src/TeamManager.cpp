#include "../include/TeamManager.h"

TeamManager::TeamManager()
{
    this->position = TEAM_MANAGER;
}

void TeamManager::work(int task)
{
    if (teamMembers.empty())
    {
        std::cout << "\t\t- Team manager #" << this->id << ": No team members in my team!\n";
    }
    else
    {
        int seed = task + this->id;
        std::srand(seed);
        int tasksQuantity = std::rand() % teamMembers.size() + 1;
        std::cout << "\t\t- Team manager #" << this->id << ": I've created " << tasksQuantity << " tasks.\n";

        for (TeamMember* t : teamMembers)
        {
            if (tasksQuantity > 0)
            {
                if (t->getTaskType() == NO_TASK)
                {
                    TaskType taskType = TaskType (std::rand() % 3);
                    t->work(taskType);
                    --tasksQuantity;
                }
                else
                {
                    std::cout   << "\t\t\t- Team member #"
                                << t->getId()
                                << " I'm already busy with task "
                                << t->getTaskTypeString(t->getTaskType())
                                << "\n";
                }
            }
            else
            {
                std::cout << "\t\t\t- Team member #"
                          << t->getId()
                          << ": "
                          << t->getTaskTypeString(t->getTaskType())
                          << "\n";
            }
        }
    }
}

std::vector<TeamMember*> *TeamManager::getTeamMembers()
{
    return &teamMembers;
}