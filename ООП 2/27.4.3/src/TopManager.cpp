#include "../include/TopManager.h"

TopManager::TopManager()
{
    this->position = TOP_MANAGER;
}

void TopManager::work(int task)
{
    if (teamManagers.empty())
    {
        std::cout << "\t- Top manager #" << this->id << ": No managers in my team!\n";
    }
    else
    {
        for (TeamManager* t : teamManagers)
        {
            t->work(task);
        }
    }
}

std::vector<TeamManager*>* TopManager::getTeamManagers()
{
    return &teamManagers;
}

bool TopManager::getIfResourcesAvailable() {
    for (TeamManager* manager : teamManagers)
    {
        for (TeamMember* member : *(manager->getTeamMembers()))
        {
            if (member->getTaskType() == NO_TASK)
                return true;
        }
    }
    return false;
}