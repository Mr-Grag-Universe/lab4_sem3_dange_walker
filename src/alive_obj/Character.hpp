#ifndef CHARACTER_CLASS
#define CHARACTER_CLASS

#include <SFML/Graphics.hpp>

#include <iostream>

#include "Alive.hpp"
#include "../containers/BackPack.hpp"
#include "../weapon/Weapon.hpp"

class Character : public Alive {
protected:
    BackPack backpack;
    std::shared_ptr<Weapon> weapon;
public:
    ObjectType get_type() override
    { return CHARACTER; }
    Character() {}
    ~Character() {}

    void read(std::ifstream & file) override;
    void draw(sf::RenderWindow & window);
    void draw_backpack_menu(sf::RenderWindow & window);
};

#endif