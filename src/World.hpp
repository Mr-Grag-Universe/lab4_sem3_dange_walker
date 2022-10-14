#ifndef MY_WORLD_CLASS
#define MY_WORLD_CLASS

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <SFML/System.hpp>

#include "Map.hpp"
#include "containers/Chest.hpp"
#include "Floor.hpp"

class World {
private:
    typedef enum ObjectTypes {
        WALL,
        FLOOR,
        DOOR,
    } ObjectTypesT;
    
    std::map <std::string, std::string> things_map {
        {"chest", "Chest"},
        {"floor", "Floor"},
    };

public:
    World(/* args */) = default;
    ~World() = default;

    static std::vector <Obj> load_things_from_file(const std::string & file_name);
    void interraction(sf::Event & event);
    void iterate();
    Map create_map() const;
};

#endif