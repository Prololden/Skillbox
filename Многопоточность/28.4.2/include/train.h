#pragma once
#include <thread>
#include <iostream>
#include "station.h"


class Train
{
    static char s_route;
    char _route;
    std::size_t _travel_time{ 0 };

public:
    Train()
    {
        _route = s_route++;
    }
    void setTravelTime(const std::size_t& travel_time)
    {
        _travel_time = travel_time;
    }
    void operator() (RailwayStation& station)
    {
        std::string message = "The train ";
        message += _route;
        message += " is on its way arrival is expected in ";
        message += std::to_string(_travel_time);
        message += " seconds";
        std::cout << message << std::endl;


        for (int i = 0; i < _travel_time; ++i)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        station.dispatcher(_route);
    }
    char getRoute()
    {
        return _route;
    }
    std::size_t getTravelTime()
    {
        return _travel_time;
    }

};

char Train::s_route = 'A';