#include <iostream>
#include "include/Player.h"
#include "include/Track.h"

int main() {
    Player player;
    do
    {
        std::cout << "Please enter the command:\n";
        std::string buffer;
        std::getline(std::cin, buffer);
        if (buffer == "exit")
        {
            break;
        }
        else if (buffer == "play")
        {
            player.play();
        }
        else if (buffer == "stop")
        {
            player.stop();
        }
        else if (buffer == "pause")
        {
            player.pause();
        }
        else if (buffer == "next")
        {
            player.next();
        }
    } while (true);

    std::cout << "Program is finished.\n";

    return 0;
}