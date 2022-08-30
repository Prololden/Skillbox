#ifndef TASK_27_3_TOPMANAGER_H
#define TASK_27_3_TOPMANAGER_H

#include "TeamManager.h"

class TopManager : public TeamManager {

private:
    std::vector<TeamManager*> teamManagers;

public:
    TopManager();
    void work(int task) override;
    std::vector<TeamManager*>* getTeamManagers();
    bool getIfResourcesAvailable();
};

#endif //TASK_27_3_TOPMANAGER_H