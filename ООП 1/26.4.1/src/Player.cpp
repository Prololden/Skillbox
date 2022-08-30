#include "../include/Player.h"

Player::Player()
{
    srand(time(nullptr));
    std::cout << "Player is loading...\n";
    std::cout << "Your playlist:\n";
    //Example base tracks:
    auto track_1 = new Track("They Come To Get Us", 112, 2010, 11, 29);
    auto track_2 = new Track("Voodoo Guitar", 298, 2012, 10, 14);
    auto track_3 = new Track("Ich Will", 246, 2001, 7, 30);
    auto track_4 = new Track("Don't Cry", 284, 1991, 10, 4);
    addToPlaylist(track_1);
    addToPlaylist(track_2);
    addToPlaylist(track_3);
    addToPlaylist(track_4);

    for (Track* t: playlist)
    {
        t->printTrackInfo();
    }
}

Player::~Player() {
    for (Track* t : playlist)
    {
        delete t;
        t = nullptr;
    }
    playlist.clear();
}

void Player::play() {
    if (currentTrack == nullptr || !currentTrack->getIsPlayed())
    {
        std::cout << "Please enter the track name: ";
        std::string trackName;
        std::getline(std::cin, trackName);
        play(trackName);
    }
}

void Player::play(const std::string& trackName)
{
    if (currentTrack != nullptr && currentTrack->getIsPlayed())
    {
        return;
    }

    for (Track* t : playlist)
    {
        if (t->getName() == trackName)
        {
            t->play();
            currentTrack = t;
            return;
        }
    }
    std::cout << "Track is not found. Try another name.\n";
}

void Player::play(int trackIndex) {
    if (!playlist.empty())
    {
        currentTrack = playlist[trackIndex];
        playlist[trackIndex]->play();
    }
}

void Player::stop()
{
    if (currentTrack != nullptr)
    {
        currentTrack->stop();
    }
    else
    {
        std::cout << "No track is selected.\n";
    }
}

void Player::pause() {
    if (currentTrack != nullptr)
    {
        currentTrack->pause();
    }
    else
    {
        std::cout << "No track is selected.\n";
    }
}

void Player::next() {
    if (currentTrack != nullptr) stop();
    if (!playlist.empty())
    {
        unsigned long trackIndex = 0;
        int safetyCounter = 20; //to prevent infinite loop.
        do {
            trackIndex = rand() % playlist.size();
            if (currentTrack == nullptr) break;
            --safetyCounter;
        } while (playlist[trackIndex]->getName() == currentTrack->getName() && safetyCounter > 0);
        play((int)trackIndex);
    }
}

void Player::addToPlaylist(Track* track)
{
    playlist.push_back(track);
}