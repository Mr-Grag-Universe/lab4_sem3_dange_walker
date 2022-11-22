#ifndef BPMOBJECT_CLASS
#define BPMOBJECT_CLASS

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "../containers/BackPack.hpp"
#include "../constants.hpp"
#include "../alive_obj/Alive.hpp"

class BPMObj : public Obj<BackPackTypeSystem> {
public:
    BPMObj() {}
    BPMObj(std::string n, pair_ui64_t p) {
        position = p;
        name = n;
    }
    virtual void draw(sf::RenderWindow & window) const = 0;
    virtual void edit(const Alive &) = 0;
};

#endif