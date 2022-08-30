#ifndef TASK_26_1_TRACK_H
#define TASK_26_1_TRACK_H
#include <iostream>
#include <ctime>
#include <iomanip>

class Track {

    enum State
    {
        PLAYING = 1,
        PAUSED = 2,
        STOPPED = 4
    };



private:
    std::string name;
    std::tm creationDate {0};
    int duration {0};
    State state = STOPPED;

public:
    Track();
    Track(std::string trackName, int trackDuration);
    Track(std::string trackName, int trackDuration, int year, int month, int day);

    std::string getName() const;
    std::tm getCreationDate() const;
    int getDuration() const;
    bool getIsPlayed() const;
    bool getIsPaused() const;
    bool getIsStopped() const;

    void setName(const std::string&);
    void setCreationDate(const int, const int, const int);
    void setDuration(const int);

    void play();
    void stop();
    void pause();
    void printTrackInfo();

};


#endif //TASK_26_1_TRACK_H