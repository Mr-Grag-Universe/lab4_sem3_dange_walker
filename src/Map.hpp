#ifndef MAP_CLASS
#define MAP_CLASS

#include <iostream>
#include <algorithm>
#include <vector>

#include "environment/Wall.hpp"
#include "environment/Floor.hpp"
#include "environment/Door.hpp"
#include "World.hpp"
#include "constants.hpp"
#include "alive_obj/Character.hpp"

class Map {
private:
    const Character & hero;
    const size_t W, H;
    std::vector <std::unique_ptr<Obj> *> all_things;
public:
    size_t get_W() const { return W; }
    size_t get_H() const { return H; }
    const std::vector <std::unique_ptr<Obj> *> & get_all_things() const {
        return all_things;
    }
    const Character & get_hero() const {
        return hero;
    }
    // Map(const World & w);
    Map(const World & w) : hero(w.get_hero()), W(w.get_W()), H(w.get_H()) {
        const std::vector <std::unique_ptr<Obj>> & at = w.get_all_things();
        for (size_t i = 0, l = at.size(); i < l; ++i) {
            std::pair <unsigned int, unsigned int> p = at[i]->get_position();
            if (distance(p, hero.get_position()) <= 1900) {
                all_things.push_back((std::unique_ptr<Obj> *) &at[i]);
                switch (at[i]->get_type()) {
                    case Obj::FLOOR:
                        env.floor.push_back((std::unique_ptr<Floor> *) &at[i]);
                        break;
                    case Obj::DOOR:
                        env.doors.push_back((std::unique_ptr<Door> *) &at[i]);
                        break;
                    case Obj::WALL:
                        env.walls.push_back((std::unique_ptr<Wall> *) &at[i]);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    ~Map() = default;
    Map(const Map & m) = default;
protected:
    struct Env {
        std::vector <std::unique_ptr<Wall> *> walls;
        std::vector <std::unique_ptr<Floor> *> floor;
        std::vector <std::unique_ptr<Door> * > doors;
    };    

private:
    Env env;
};

#endif