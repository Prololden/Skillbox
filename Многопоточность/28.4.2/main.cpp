#include <iostream>
#include <vector>
#include "station.h"

int main()
{
    RailwayStation station(3);
    station.setTravelTime();
    station.startTrain();
    return 0;
}