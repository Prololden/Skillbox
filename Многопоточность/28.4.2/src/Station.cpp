#include "station.h"
#include "train.h"

RailwayStation::RailwayStation(int sizeTrain) : _sizeTrain(sizeTrain)
{
    for (int i = 0; i < _sizeTrain; ++i)
    {
        _train.push_back(new Train);
    }
}

RailwayStation::~RailwayStation()
{
    for (auto& th : _thred_train)
    {
        if (th.joinable())
        {
            th.join();

        }

    }

    for (auto& train : _train)
        delete train;
}

bool RailwayStation::trainEmpty() const
{
    if (_train.empty())
    {
        std::cout << "No train" << std::endl;
        return true;
    }
    return false;
}

void RailwayStation::setTravelTime()
{
    if (trainEmpty())
        return;

    int travel_time;
    for (auto train : _train)
    {
        std::cout << "Enter the time of the train's " << train->getRoute() << " journey to the station: ";
        std::cin >> travel_time;
        train->setTravelTime(travel_time);
    }
}

void RailwayStation::startTrain()
{
    if (trainEmpty())
        return;

    for (int i = 0; i < _train.size(); ++i)
    {
        _thred_train.push_back(std::thread(std::ref(*_train[i]), std::ref(*this)));

    }
}

void RailwayStation::dispatcher(const char& route)
{
    if (_close)
    {
        std::string train;
        train = "The train ";
        train += route;
        train += " is waiting for a free path";
        std::cout << train << std::endl;
    }

    station.lock();
    {
        _close = true;
        std::string answer, train;
        train = "The train ";
        train += route;
        train += " arrived at the station";
        std::cout << train << std::endl;
        train = "Enter depart train ";
        train += route;
        std::cout << train << std::endl;
        std::cin >> answer;
        train = "The train ";
        train += route;
        train += " departs from the station";
        std::cout << train << std::endl;
        _close = false;
    }
    station.unlock();

}