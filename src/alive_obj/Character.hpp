#ifndef CHARACTER_CLASS
#define CHARACTER_CLASS

#include <SFML/Graphics.hpp>

#include <iostream>
#include <algorithm>

#include "Alive.hpp"
#include "../Effect.hpp"
#include "../containers/BackPack.hpp"
#include "../weapon/Weapon.hpp"
#include "../World.hpp"

class Character : public Alive {
protected:
    BackPack backpack;
    std::shared_ptr<Weapon> weapon;
    World & world;
public:
    void fill_backpack();
    GameTypeSystem get_type() const override
    { return CHARACTER; }
    const World & get_world() const 
    { return world; }
    const BackPack & get_backpack() const 
    { return backpack; }

    Character(World & w) : world(w) {}
    ~Character() {}

    void read(std::ifstream & file) override;
    void draw(sf::RenderWindow & window);
    void draw_backpack_menu(sf::RenderWindow & window);
    std::shared_ptr<Effect> use_weapon();
};

#endif