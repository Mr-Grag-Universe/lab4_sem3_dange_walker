#ifndef CHARACTER_CLASS
#define CHARACTER_CLASS

#include <iostream>
#include <algorithm>
#include <vector>

#include "Alive.hpp"
#include "../Effect.hpp"
#include "../containers/BackPack.hpp"
#include "../weapon/Weapon.hpp"
#include "./quest/quest.hpp"
#include "../loot/Money.hpp"

class World;

static std::vector <size_t> exp_levels = {0, 10, 20, 50, 100, 200, 500, 1000};

class Character : public Alive {
protected:
    BackPack backpack;
    std::shared_ptr<Weapon> weapon;
    World & world;
    size_t level = 0;
    int experience = 1;
    size_t max_exp = 10;

    std::vector <std::shared_ptr<Quest>> quests;
    Money money = Money();
public:
    void fill_backpack();
    void level_up()
    { ++level; }
    void exp_restart()
    { experience = 0; }
    void set_max_exp(size_t m_exp)
    { max_exp = m_exp; }
    void plus_exp(int exp) {
        experience += exp;
        if (exp < 0) {
            std::cerr << "negative exp" << std::endl;
            throw std::invalid_argument("i'm too lazy to write this logic");
        }
        while ((size_t) exp >= max_exp) {
            exp -= max_exp;
            ++level;
            if (level+1 > exp_levels.size()) {
                exp = max_exp;
                throw std::invalid_argument("hero level is too big");
            }
            max_exp = exp_levels[level+1];
            std::cout << "congratulations! you achived a new " << level << " level" << std::endl;
        }
    }

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
    std::shared_ptr<Effect> use_weapon();

    //============ getters =============//

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

    size_t get_exp() const
    { return experience; }
    
    size_t get_max_exp() const
    { return max_exp; }

    const std::vector <std::shared_ptr<Quest>> & get_quests() const
    { return quests; }
    std::vector <std::shared_ptr<Quest>> & get_quests()
    { return quests; }

    //========== other methods =========//

    void push_quest(std::shared_ptr<Quest> quest);
    
    void receave_money(Money m)
    { money = money + m; }
};

#endif