#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>

class Train;

class RailwayStation
{
    int _sizeTrain;
    bool _close{ false };
    std::vector<Train*> _train;
    std::vector<std::thread> _thred_train;
    std::mutex station;
    void dispatcher(const char& route);
    bool trainEmpty() const;
    friend class Train;
public:
    RailwayStation(int sizeTrain = 0);
    ~RailwayStation();
    void setTravelTime();
    void startTrain();
};