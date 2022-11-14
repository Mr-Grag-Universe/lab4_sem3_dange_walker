#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "backpack_menu.hpp"
#include "../World_old.hpp"
#include "../Object.hpp"
#include "../constants.hpp"
#include "Skin.hpp"

template<>
std::vector <std::shared_ptr<Obj<BackPackTypeSystem>>> World<BackPackTypeSystem>::load_things_from_file(const std::string & file_name);

template<>
World<BackPackTypeSystem>::World(const std::string & file_name) : World() {
    this->all_things = load_things_from_file(file_name);
}
template<>
World<BackPackTypeSystem>::World(std::vector <std::shared_ptr<Obj<BackPackTypeSystem>>> things) : World() {
    all_things = std::move(things);
}

template<>
std::shared_ptr<Obj<BackPackTypeSystem>> World<BackPackTypeSystem>::load_object(std::string type, std::ifstream & file) {
    std::shared_ptr<Obj<BackPackTypeSystem>> obj;
    switch (bp_menu_types[type]) {
        case SKIN: {
            obj = std::make_shared<Skin>();
            break;
        }
        default:
            break;
    }
    obj->read(file);
    return obj;
}

template<>
std::vector <std::shared_ptr<Obj<BackPackTypeSystem>>> World<BackPackTypeSystem>::load_things_from_file(const std::string & file_name) {
    std::cout << "#=#=#=#=# opening fstream with \"" << file_name << "\" file..." << std::endl;
    std::ifstream file(file_name);
    if (!file) {
        std::cout << "cannot find this file: " << file_name << std::endl;
        throw std::invalid_argument("cannot find stream file");
    }

    std::string type;
    std::vector <std::shared_ptr<Obj<BackPackTypeSystem>>> v;
    while (file >> type) {
        if (type.substr(0, 2) == "//") {
            std::cout << type << "\n";
            continue;
        }
        std::cout << "object type: " << type << "\n";
        v.push_back(load_object(type, file));
    }

    file.close();

    return v;
}

template<>
void World<BackPackTypeSystem>::interraction(sf::Event & event, sf::RenderWindow & window) {
    switch (event.type) {
    case sf::Event::KeyPressed: {
        if (this->mode == RUN) {
            game_interraction(event, window);
        } else if (this->mode == MENU) {
            menu_interraction(event, window);
        } else if (this->mode == BACKPACK_MENU) {
            backpack_menu_interraction(event, window);
        }

        break;
    }
    case sf::Event::Resized: {
        W = event.size.width;
        H = event.size.height;
        hero.set_sprite_position(std::make_pair((W-hero.get_texture()->getSize().x)/2, (H-hero.get_texture()->getSize().y)/2));
        std::cout << "new width: " << event.size.width << std::endl;
        std::cout << "new height: " << event.size.height << std::endl;
        break;
    }
    case sf::Event::MouseButtonPressed: {
        if (this->mode == RUN) {
            game_interraction(event, window);
        } else if (this->mode == MENU) {
            menu_interraction(event, window);
        } else if (this->mode == BACKPACK_MENU) {
            backpack_menu_interraction(event, window);
        }

        break;
    }
    default:
        break;
    }
    return;
}

template<>
void World<BackPackTypeSystem>::iterate() {
    std::pair <unsigned int, unsigned int> p_h = hero.get_position();
    for (size_t i = 0; i < all_npc.size(); ++i) {
        if (all_npc[i]->get_attitude() == NPC::BAD) {
            if (distance(all_npc[i]->get_position(), p_h) < all_npc[i]->get_visability_radius()) {
                all_npc[i]->set_velocity(3);
                std::pair <unsigned int, unsigned int> p_o = all_npc[i]->get_position();
                double d_x = (long long) p_h.first - (long long) p_o.first;
                double d_y = (long long) p_h.second - (long long) p_o.second;
                double a = atan(d_y/d_x);
                all_npc[i]->set_v_angle(a);
            } else {
                all_npc[i]->set_velocity(0);
            }
        } 
    }

    for (size_t i = 0; i < all_npc.size(); ++i) {
        if (all_npc[i]->is_mobile()) {
            double v = all_npc[i]->get_velocity();
            if (v == 0)
                continue;
            double a = all_npc[i]->get_v_angle();
            int v_x = v * cos(a);
            int v_y = v * sin(a);
            all_npc[i]->move(v_x, v_y);
        }
    }
    
    for (size_t i = 0; i < all_effects.size(); ++i) {
        if (all_effects[i]->makes_damage()) {
            for (size_t j = 0; j < all_npc.size(); ++j) {
                if (&all_effects[j]->get_originator_ptr() != &(*all_npc[i])) {
                    all_effects[i]->make_damage(*(all_npc[j]));
                    if (all_npc[j]->get_helth() == 0) {
                        std::cout << all_npc[j]->get_name() << "has been killed" << std::endl;
                        all_npc.erase(all_npc.begin() + j);
                        j--;
                    }
                }
            }
        }
        if (all_effects[i]->get_time() > all_effects[i]->get_life_time()) {
            all_effects.erase(all_effects.begin() + i);
            i--;
        } else
            all_effects[i]->update_texture();
    }

    return;
}

template<>
void World<BackPackTypeSystem>::add_things_from_file(const std::string & file_name) {
    std::vector <std::shared_ptr<Obj<BackPackTypeSystem>>> things = load_things_from_file(file_name);

    [[maybe_unused]] size_t old_len = all_things.size();
    all_things.insert(
        all_things.end(),
        std::make_move_iterator(things.begin()),
        std::make_move_iterator(things.end())
    );
    [[maybe_unused]] size_t new_len = all_things.size();
    [[maybe_unused]] size_t th_len = things.size();
}