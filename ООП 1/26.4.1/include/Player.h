#ifndef TASK_26_1_PLAYER_H
#define TASK_26_1_PLAYER_H

#include "Track.h"
#include <iostream>
#include <vector>
#include <random>

class Player {

private:
    Track* currentTrack{nullptr};
    std::vector<Track*> playlist;
    void play(int trackIndex);
    void play(const std::string& trackName);

public:

    Player();
    ~Player();

    void play();
    void stop();
    void pause();
    void next();
    void addToPlaylist(Track* track);

};


#endif //TASK_26_1_PLAYER_H