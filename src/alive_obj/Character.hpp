#ifndef CHARACTER_CLASS
#define CHARACTER_CLASS

#include <SFML/Graphics.hpp>

#include <iostream>
#include <algorithm>

#include "Alive.hpp"
#include "../Effect.hpp"
#include "../containers/BackPack.hpp"
#include "../weapon/Weapon.hpp"

class World;

class Character : public Alive {
protected:
    BackPack backpack;
    std::shared_ptr<Weapon> weapon;
    World & world;
    size_t level = 0;
    size_t experience = 1;
    size_t max_exp = 100;
public:
    void fill_backpack();
    GameTypeSystem get_type() const override
    { return CHARACTER; }
    const World & get_world() const 
    { return world; }
    World & get_world() 
    { return world; }
    const BackPack & get_backpack() const 
    { return backpack; }
    BackPack & get_backpack() 
    { return backpack; }
    size_t get_level() const
    { return level; }
    void level_up()
    { ++level; }
    size_t get_exp() const
    { return experience; }
    size_t get_max_exp() const
    { return max_exp; }
    void exp_restart()
    { experience = 0; }
    void set_max_exp(size_t m_exp)
    { max_exp = m_exp; }

    Character(World & w) : world(w) {}
    ~Character() {}
    Character(const Character & c) = default;
    Character & operator=(const Character & c) {
        name = c.name;
        collider = c.collider;
        backpack = c.backpack;
        experience = c.experience;
        health = c.health;
        // world = c.world;
        weapon = c.weapon;
        visibility_radius = c.visibility_radius;
        position = c.position;
        level = c.level;
        layer = c.layer;
        return *this;
    }

    void read(std::ifstream & file) override;
    void draw(sf::RenderWindow & window);
    void draw_backpack_menu(sf::RenderWindow & window);
    std::shared_ptr<Effect> use_weapon();
};

#endif