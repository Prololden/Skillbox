#include <iostream>
#include <nlohmann/json.hpp>
#include <map>
#include <fstream>

struct Film
{
    std::string name;
    std::map<std::string, std::string> actors;
    int year;
    std::string country;
    std::string studio;
    std::string director;
    std::string screenwriter;
    std::string producer;
};


int main() {
    const std::string OUTPUT_PATH = "..\\films.json";
    std::cout << "Creating film data...\n";
    Film film;
    film.name = "What We Do in the Shadows";
    film.actors = {{"Vladislav", "Jemaine Clement"}, {"Viago", "Taika Waititi"}};
    film.year = 2014;
    film.country = "New Zealand";
    film.studio = "Defender films, Two canoes pictures";
    film.director = "Taika Waititi";
    film.screenwriter = "Taika Waititi";
    film.producer = "Emma Bartlett";

    std::cout << "Opening file...\n";
    std::ofstream file(OUTPUT_PATH);
    if (file.is_open())
    {
        std::cout << "Writing to JSON file [" << OUTPUT_PATH << "]...\n";
        nlohmann::json dict;
        dict["name"] = film.name;
        dict["actors"] = film.actors;
        dict["year"] = film.year;
        dict["country"] = film.country;
        dict["studio"] = film.studio;
        dict["director"] = film.director;
        dict["screenwriter"] = film.screenwriter;
        dict["producer"] = film.producer;
        std::cout << "Writing is finished.\n";
        file << dict;
        file.close();
        std::cout << "File is closed.\n";
    }
    return 0;
}