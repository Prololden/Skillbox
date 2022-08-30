#include "../include/Track.h"

#include <utility>

Track::Track() = default;

Track::Track(std::string trackName, int trackDuration) {
    name = std::move(trackName);
    duration = trackDuration;
    state = STOPPED;
}

Track::Track(std::string trackName, int trackDuration, int year, int month, int day) {
    name = std::move(trackName);
    duration = trackDuration;
    state = STOPPED;
    setCreationDate(year, month, day);
}

void Track::setName(const std::string& newName) {
    name = newName;
}

std::string Track::getName() const {
    return name;
}

std::tm Track::getCreationDate() const {
    return creationDate;
}

int Track::getDuration() const {
    return duration;
}

bool Track::getIsPlayed() const {
    return state == PLAYING;
}

bool Track::getIsPaused() const {
    return state == PAUSED;
}

bool Track::getIsStopped() const {
    return state == STOPPED;
}

void Track::setCreationDate(const int year, const int month, const int day) {
    creationDate.tm_year = year - 1900;
    creationDate.tm_mon = month - 1;
    creationDate.tm_mday = day;
}

void Track::setDuration(const int newDuration) {
    duration = newDuration;
}

void Track::play() {
    if (state != PLAYING)
    {
        state = PLAYING;
        std::cout << "---------------------------------------\n";
        std::cout << "Track is played: " << name << "\n";
        std::cout << "Duration: " << duration << " seconds\n";
        std::cout << "Created: " << std::put_time(&creationDate, "%Y %b %d") << "\n";
    }
}

void Track::stop() {
    if (state != STOPPED)
    {
        state = STOPPED;
        std::cout << "---------------------------------------\n";
        std::cout << "Track is stopped: " << name << "\n";
    }
}

void Track::pause() {
    if (state != PAUSED)
    {
        state = PAUSED;
        std::cout << "---------------------------------------\n";
        std::cout << "Track is paused: " << name << "\n";
    }
}

void Track::printTrackInfo() {
    std::cout << "\t - " << name << ", "
              << duration << " sec, "
              << std::put_time(&creationDate, "%Y %b %d") << "\n";
}