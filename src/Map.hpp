#ifndef MAP_CLASS
#define MAP_CLASS

#include <algorithm>
#include <vector>

#include "Wall.hpp"
#include "Floor.hpp"
#include "Door.hpp"

class Map {
public:
    Map() = default;
    ~Map() = default;
    Map(const Map & m) = default;
protected:
    // std::vector <Wall> walls;
    // std::vector <Floor> floor;
    // std::vector <Door> doors;

private:
};

#endif